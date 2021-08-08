#pragma once

#include "pch.h"
#include "BaseComponents/Creators/BaseComponentCreator.h"

#pragma comment (lib, "Comctl32.lib")
#pragma comment (lib, "UxTheme.lib")

#pragma comment (lib, "JSON.lib")
#pragma comment (lib, "ThreadPool.lib")

namespace gui_framework
{
	/// @brief Singleton with GUIFramework settings and some functionality
	class GUI_FRAMEWORK_API GUIFramework
	{
	private:
		json::JSONParser jsonSettings;
		threading::ThreadPool threadPool;
		INITCOMMONCONTROLSEX comm;
		std::unordered_map<std::string, HMODULE> modules;
#pragma region Ids
		std::unordered_multimap<std::wstring, uint32_t> generatedIds;
		std::queue<uint32_t> availableIds;
		std::mutex idMutex;
		uint32_t nextId;
#pragma endregion
#pragma region Hotkeys
		std::vector<std::function<void()>> hotkeys;
		std::queue<uint32_t> availableHotkeyIds;
		std::mutex hotkeyIdMutex;
		uint32_t nextHotkeyId;
#pragma endregion
#pragma region ComponentsFinding
		std::vector<BaseComponent*> components;
		std::mutex componentsMutex;
#pragma endregion
		std::unordered_map<size_t, std::unique_ptr<utility::BaseComponentCreator>> creators;

	private:
		void initCreators();

		void addComponent(BaseComponent* component);

		void removeComponent(BaseComponent* component);

	private:
		uint32_t generateId(const std::wstring& windowName);

		void removeIds(const std::wstring& windowName);

		void removeId(const std::wstring& windowName, uint32_t id);

		std::vector<uint32_t> getIds(const std::wstring& windowName);

		void processHotkey(uint32_t hotkey) const;

	private:
		GUIFramework();

		~GUIFramework();

	public:
		/// @brief Singleton instance access
		/// @return Singleton instance
		/// @exception json::exceptions::CantFindValueException Unable to find setting in gui_framework.json on first GUIFramework::get() call
		static GUIFramework& get();

		/// @brief Add task to thread pool. Thread safe method
		/// @param task Task function
		/// @param callback After execution task callback function
		void addTask(const std::function<void()>& task, const std::function<void()>& callback = nullptr);

		/// @brief Add task to thread pool. Thread safe method
		/// @param task Task function
		/// @param callback After execution task callback function
		void addTask(std::function<void()>&& task, const std::function<void()>& callback = nullptr);

		/// @brief Only works in thread, that call runMainLoop from WindowHolder. Thread safe register hotkey
		/// @param hotkey Value from https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
		/// @param additionalKeys 
		/// @param noRepeat 
		/// @return Hotkey id
		/// @exception GetLastErrorException 
		uint32_t registerHotkey(uint32_t hotkey, const std::function<void()>& onClick, const std::vector<hotkeys::additionalKey>& additionalKeys = {}, bool noRepeat = false);

		/// @brief Thread safe unregister hotkey
		/// @param hotkeyId 
		/// @return Success
		bool unregisterHotkey(uint32_t hotkeyId);

		/// @brief Load module with some sort of data
		/// @param moduleName Name of that module
		/// @param pathToModule Path to that module
		/// @excepiton FileDoesNotExist 
		/// @exception CantLoadModule 
		void loadModule(const std::string& moduleName, const std::filesystem::path& pathToModule);

		/// @brief Unload module
		/// @param moduleName Name of module to unload
		void unloadModule(const std::string& moduleName);

		/// @brief Add derived from BaseComponentCreator creator
		template<std::derived_from<BaseComponent> T, std::derived_from<utility::BaseComponentCreator> CreatorT, typename... Args>
		void addCreator(Args&&... args);

		/// @brief Thread safe 
		/// @param handle 
		/// @return Found component or nullptr
		BaseComponent* findComponent(HWND handle);

		/// @brief Thread safe
		/// @param componentName 
		/// @return Found component or nullptr
		BaseComponent* findComponent(const std::wstring& componentName);

		/// @brief Check if component created. If component destroyed after you call findComponent, you may have not valid pointer
		/// @param component Value from 
		/// @return true if exist, false otherwise
		bool isExist(BaseComponent* component);

		/// @brief Get all current registered creators
		/// @return creators
		const std::unordered_map<size_t, std::unique_ptr<utility::BaseComponentCreator>>& getCreators() const;

		/// @brief Get settings from gui_framework.json
		/// @return jsonSettings
		const json::JSONParser& getJSONSettings() const;

		const std::unordered_map<std::string, HMODULE>& getModules() const;
#pragma region FriendClasses
		friend class BaseComponent;

		friend class WindowHolder;
#pragma endregion
	};

	inline GUIFramework& GUIFramework::get()
	{
		static GUIFramework instance;

		return instance;
	}

	template<std::derived_from<BaseComponent> T, std::derived_from<utility::BaseComponentCreator> CreatorT, typename... Args>
	void GUIFramework::addCreator(Args&&... args)
	{
		creators[typeid(T).hash_code()] = std::unique_ptr<CreatorT>(new CreatorT(std::forward<Args>(args)...));
	}
}
