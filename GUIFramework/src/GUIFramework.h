#pragma once

#include <future>
#include <shared_mutex>
#include <mutex>
#include <algorithm>

#include "Utility/Creators/BaseComponentCreator.h"
#include "Interfaces/Utility/IDeserializer.h"
#include "Utility/Keys.h"

#pragma comment (lib, "Comctl32.lib")
#pragma comment (lib, "UxTheme.lib")

#pragma comment (lib, "JSON.lib")
#pragma comment (lib, "ThreadPool.lib")
#pragma comment (lib, "Localization.lib")

namespace gui_framework
{
	/// @brief Singleton with GUIFramework settings and some functionality
	class GUI_FRAMEWORK_API GUIFramework
	{
	public:
		struct GUI_FRAMEWORK_API hotkeyData
		{
			uint32_t key;
			std::function<void()> hotkeyEvent;
			std::string functionName;
			std::string moduleName;
			std::vector<hotkeys::additionalKeys> additionalKeys;
		
			hotkeyData();

			hotkeyData(uint32_t key, const std::function<void()>& hotkeyEvent, const std::vector<hotkeys::additionalKeys>& additionalKeys);

			hotkeyData(uint32_t key, const std::string& functionName, const std::string& moduleName, const std::vector<hotkeys::additionalKeys>& additionalKeys);

			hotkeyData(const hotkeyData&) = default;

			hotkeyData(hotkeyData&&) noexcept = default;

			hotkeyData& operator = (const hotkeyData&) = default;

			hotkeyData& operator = (hotkeyData&&) noexcept = default;

			~hotkeyData() = default;
		};

	private:
		static std::unique_ptr<GUIFramework> instance;

	private:
		json::JSONParser jsonSettings;
		std::unique_ptr<threading::ThreadPool> threadPool;
		INITCOMMONCONTROLSEX comm;
		std::unordered_map<std::string, HMODULE> modules;
		std::unordered_map<std::string, std::string> modulesPaths;
		std::unordered_map<size_t, smartPointerType<utility::BaseComponentCreator>> creators;
		std::unordered_map<size_t, smartPointerType<interfaces::IDeserializer>> deserializers;
		DWORD uiThreadId;
#pragma region Ids
		std::unordered_multimap<std::wstring, uint32_t> generatedIds;
		std::queue<uint32_t> availableIds;
		std::mutex idMutex;
		uint32_t nextId;
		std::atomic<uint32_t> nextTrayId;
#pragma endregion
#pragma region Hotkeys
		std::unordered_map<size_t, std::function<void()>> hotkeys;
		std::vector<std::set<uint32_t>> allHotkeys;
		std::unordered_map<size_t, hotkeyData> serializableHotkeysData;
		std::mutex hotkeyIdMutex;
#pragma endregion
#pragma region ComponentsFinding
		std::vector<BaseComponent*> components;
		std::recursive_mutex componentsMutex;
#pragma endregion
#pragma region Modules
		std::vector<std::unique_ptr<threading::Future>> asyncModulesHandles;
		std::mutex loadModulesMutex;
		std::vector<std::string> cantLoadedModules;
#pragma endregion
#pragma region RunOnUIThread
		std::recursive_mutex runOnUIThreadMutex;
		std::queue<std::function<void()>> runOnUIFunctions;
#pragma endregion

	private:
		void initCreators();

		void initDeserializers();

		void addComponent(BaseComponent* component);

		void removeComponent(BaseComponent* component);

	private:
		uint32_t generateId(const std::wstring& windowName);

		uint32_t generateTrayId();

		void removeIds(const std::wstring& windowName);

		void removeId(const std::wstring& windowName, uint32_t id);

		std::vector<uint32_t> getIds(const std::wstring& windowName);

		void processHotkeys() const;

		void initUIThreadId();

		void loadModule(const std::string& modulePath, const std::string& moduleName);

		void loadModulesFromSettings(const json::utility::jsonObject& settingsObject);

	private:
		GUIFramework();

		~GUIFramework();

	public:
		/// @brief Singleton instance access
		/// @return Singleton instance
		/// @exception json::exceptions::CantFindValueException Unable to find setting in gui_framework.json on first GUIFramework::get() call
		/// @excepiton std::runtime_error Can't find gui_framework.json
		static GUIFramework& get();

		/// @brief Run function in UI thread. Functions processed only when window in main UI thread has focus
		/// @param function Function that will run in UI thread
		static void runOnUIThread(const std::function<void()>& function);

		/// @brief Run function in UI thread. Functions processed only when window in main UI thread has focus
		/// @param function Function that will run in UI thread
		static void runOnUIThread(std::function<void()>&& function);

		/// @brief Restart application with given exit code
		/// @param exitCode Exit code for previous application
		/// @exception GetLastErrorException 
		static void restartApplication(int exitCode = 0);

		/// @brief Getter for UI thread id
		/// @return uiThreadId
		static DWORD getUIThreadId();

	public:
		/// @brief Add task to thread pool. Thread safe method
		/// @param task Task function
		/// @param callback After execution task callback function
		/// @exception std::runtime_error Can't find threadsCount setting in gui_framework.json
		std::unique_ptr<threading::Future> addTask(const std::function<void()>& task, const std::function<void()>& callback = nullptr);

		/// @brief Add task to thread pool. Thread safe method
		/// @param task Task function
		/// @param callback After execution task callback function
		/// @exception std::runtime_error Can't find threadsCount setting in gui_framework.json
		std::unique_ptr<threading::Future> addTask(const std::function<void()>& task, std::function<void()>&& callback);

		/// @brief Add task to thread pool. Thread safe method
		/// @param task Task function
		/// @param callback After execution task callback function
		/// @exception std::runtime_error Can't find threadsCount setting in gui_framework.json
		std::unique_ptr<threading::Future> addTask(std::function<void()>&& task, const std::function<void()>& callback = nullptr);

		/// @brief Add task to thread pool. Thread safe method
		/// @param task Task function
		/// @param callback After execution task callback function
		/// @exception std::runtime_error Can't find threadsCount setting in gui_framework.json
		std::unique_ptr<threading::Future> addTask(std::function<void()>&& task, std::function<void()>&& callback);

		/// @brief Only works in thread, that call runMainLoop from WindowHolder. Thread safe register hotkey
		/// @param key Value from keys enum or https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
		/// @param onClick Function to call
		/// @param additionalKeys 
		/// @return Hotkey id
		size_t registerHotkey(hotkeys::keys key, const std::function<void()>& onClick, const std::vector<hotkeys::additionalKeys>& additionalKeys = {});

		/// @brief Only works in thread, that call runMainLoop from WindowHolder. Thread safe register hotkey
		/// @param key Value from keys enum or https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
		/// @param functionName Name of function to call
		/// @param moduleName Name of module where function store
		/// @param additionalKeys 
		/// @return Hotkey id
		/// @exception CantFindFunctionFromModuleException 
		/// @exception std::out_of_range Can't find moduleName in loaded modules
		size_t registerHotkey(hotkeys::keys key, const std::string& functionName, const std::string& moduleName, const std::vector<hotkeys::additionalKeys>& additionalKeys = {});

		/// @brief Thread safe unregister hotkey
		/// @param hotkeyId Return value from registerHotkey
		/// @return Is successed
		bool unregisterHotkey(size_t hotkeyId);

		/// @brief Thread safe unregister hotkey
		/// @param key Value from https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
		/// @param additionalKeys
		/// @return Is successed
		bool unregisterHotkey(uint32_t key, const std::vector<hotkeys::additionalKeys>& additionalKeys = {});

		/// @brief Thread safe get hotkeys
		/// @return Registered hotkeys
		std::vector<hotkeyData> getRegisteredHotkeys();

		/// @brief Load module with some sort of data
		/// @param moduleName Name of that module
		/// @param pathToModule Path to that module
		/// @excepiton FileDoesNotExist 
		/// @exception CantLoadModule 
		void loadModule(const std::string& moduleName, const std::filesystem::path& pathToModule);

		/// @brief Unload module
		/// @param moduleName Name of module to unload
		void unloadModule(const std::string& moduleName);

		/// @brief Check if component created. If component destroyed after you call findComponent, you may have not valid pointer
		/// @param component Value from 
		/// @return true if exist, false otherwise
		bool isExist(BaseComponent* component);

		/// @brief Serialize hotkeys
		/// @return JSON array with hotkeys data
		std::vector<json::utility::jsonObject> serializeHotkeys();

		/// @brief Deserialize hotkeys
		/// @param description Description of holder window with 'hotkeys' object
		void deserializeHotkeys(const json::utility::jsonObject& description);

		/// @brief Check if modules are loaded. You can call getCantLoadedModules() to check if loaded modules have failed
		/// @return 
		bool isModulesLoaded() const;

		/// @brief Change localization for all components
		/// @param language New language
		void changeLocalization(const std::string& language) const;

		/// @brief Get all current registered creators
		/// @return creators
		const std::unordered_map<size_t, smartPointerType<utility::BaseComponentCreator>>& getCreators() const;

		/// @brief Get all current registered deserializers
		/// @return deserializers
		const std::unordered_map<size_t, smartPointerType<interfaces::IDeserializer>>& getDeserializers() const;

		/// @brief Get settings from gui_framework.json
		/// @return jsonSettings
		const json::JSONParser& getJSONSettings() const;

		/// @brief Get all loaded modules
		/// @return 
		const std::unordered_map<std::string, HMODULE>& getModules() const;

		/// @brief Get all loaded modules paths
		/// @return 
		const std::unordered_map<std::string, std::string>& getModulesPaths() const;

		/// @brief List of all exceptions in load modules process
		/// @return 
		std::vector<std::string> getCantLoadedModules();

		/**
		 * @brief Get handle to specific module
		 * @param moduleName 
		 * @return 
		 * @exception std::out_of_range
		*/
		HMODULE operator [](const std::string& moduleName) const;

		/// @brief Thread safe 
		/// @param handle 
		/// @return Found component or nullptr
		template<typename T = BaseComponent>
		T* findComponent(HWND handle);

		/// @brief Thread safe
		/// @param componentName 
		/// @return Found component or nullptr
		template<typename T = BaseComponent>
		T* findComponent(const std::wstring& componentName);

		/// @brief Add derived from BaseComponentCreator creator
		template<std::derived_from<BaseComponent> T, std::derived_from<utility::BaseComponentCreator> CreatorT, typename... Args>
		void addCreator(Args&&... args);

		/// @brief Add derived from IDeserializer deserializer
		template<std::derived_from<BaseComponent> T, std::derived_from<interfaces::IDeserializer> DeserializerT, typename... Args>
		void addDeserializer(Args&&... args);
#pragma region FriendClasses
		friend class BaseComponent;
		friend class WindowHolder;
		friend class BaseDialogBox;
		friend class BaseMainWindow;
		friend struct std::default_delete<GUIFramework>;
#pragma endregion
	};

	template<typename T>
	T* GUIFramework::findComponent(HWND handle)
	{
		std::unique_lock<std::recursive_mutex> lock(componentsMutex);

		auto it = std::ranges::find_if(components, [&handle](BaseComponent* component) { return component->getHandle() == handle; });

		return it == components.end() ? nullptr : dynamic_cast<T*>(*it);
	}

	template<typename T>
	T* GUIFramework::findComponent(const std::wstring& componentName)
	{
		std::unique_lock<std::recursive_mutex> lock(componentsMutex);

		auto it = std::ranges::find_if(components, [&componentName](BaseComponent* component) { return component->getWindowName() == componentName; });

		return it == components.end() ? nullptr : dynamic_cast<T*>(*it);
	}

	template<std::derived_from<BaseComponent> T, std::derived_from<utility::BaseComponentCreator> CreatorT, typename... Args>
	void GUIFramework::addCreator(Args&&... args)
	{
		creators[typeid(T).hash_code()] = smartPointerType<CreatorT>(new CreatorT(std::forward<Args>(args)...));
	}

	template<std::derived_from<BaseComponent> T, std::derived_from<interfaces::IDeserializer> DeserializerT, typename... Args>
	void GUIFramework::addDeserializer(Args&&... args)
	{
		deserializers[typeid(T).hash_code()] = smartPointerType<DeserializerT>(new DeserializerT(std::forward<Args>(args)...));
	}
}
