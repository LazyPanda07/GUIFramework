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
		HMODULE msftEditModule;
#pragma region Ids
		std::unordered_multimap<std::wstring, uint32_t> generatedIds;
		std::queue<uint32_t> availableIds;
		std::mutex idMutex;
		uint32_t nextId;
#pragma endregion
#pragma region Hotkeys
		std::vector<std::function<void()>> hotkeys;
		std::queue<uint32_t> availableHotkeyIds;
		uint32_t nextHotkeyId;
#pragma endregion
		std::unordered_map<size_t, std::unique_ptr<utility::BaseComponentCreator>> creators;

	private:
		void initCreators();

	private:
		GUIFramework();

		~GUIFramework();

	public:
		/// @brief 
		/// @return
		/// @exception json::exceptions::CantFindValueException Unable to find setting in gui_framework.json on first GUIFramework::get() call
		static GUIFramework& get();

		/// @brief 
		/// @param hotkey 
		/// @exceptions std:out_of_range 
		void processHotkey(uint32_t hotkey) const;

		/// @brief Add task to thread pool. Thread safe method
		/// @param task 
		/// @param callback 
		void addTask(const std::function<void()>& task, const std::function<void()>& callback = nullptr);

		/// @brief Add task to thread pool. Thread safe method
		/// @param task 
		/// @param callback 
		void addTask(std::function<void()>&& task, const std::function<void()>& callback = nullptr);

		/// @brief Thread safe generating id
		/// @param windowName 
		/// @return 
		uint32_t generateId(const std::wstring& windowName);

		/// @brief Thread safe remove ids
		/// @param windowName 
		void removeIds(const std::wstring& windowName);

		/// @brief Thread safe remove id
		/// @param windowName 
		/// @param HMENU 
		void removeId(const std::wstring& windowName, uint32_t id);

		/// @brief 
		/// @param hotkey Value from https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
		/// @param additionalKeys 
		/// @param noRepeat 
		/// @return Hotkey id
		/// @exception GetLastErrorException 
		uint32_t registerHotkey(uint32_t hotkey, const std::function<void()>& onClick, const std::vector<hotkeys::additionalKey>& additionalKeys = {}, bool noRepeat = false);

		/// @brief 
		/// @param hotkeyId 
		/// @return 
		bool unregisterHotkey(uint32_t hotkeyId);

		template<std::derived_from<BaseComponent> T, std::derived_from<utility::BaseComponentCreator> CreatorT, typename... Args>
		void addCreator(Args&&... args);

		/// @brief Thread safe ids getter
		/// @param windowName 
		/// @return 
		std::vector<uint32_t> getIds(const std::wstring& windowName);

		const std::unordered_map<size_t, std::unique_ptr<utility::BaseComponentCreator>>& getCreators() const;

		const json::JSONParser& getJSONSettings() const;
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
