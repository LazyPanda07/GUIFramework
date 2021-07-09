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
		std::unordered_multimap<std::wstring, uint32_t> autoGeneratedHMENUs;
		std::unordered_map<size_t, std::unique_ptr<utility::BaseComponentCreator>> creators;
		uint32_t nextHMENU;

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

		void addTask(const std::function<void()>& task, const std::function<void()>& callback = nullptr);

		void addTask(std::function<void()>&& task, const std::function<void()>& callback = nullptr);

		uint32_t generateHMENU(const std::wstring& windowName);

		void removeHMENUs(const std::wstring& windowName);

		void removeHMENU(const std::wstring& windowName, uint32_t hmenu);

		void addCreator(size_t hash, std::unique_ptr<utility::BaseComponentCreator>&& creator);

		std::vector<uint32_t> getHMENUs(const std::wstring& windowName);

		const std::unordered_map<size_t, std::unique_ptr<utility::BaseComponentCreator>>& getCreators() const;

		const json::JSONParser& getJSONSettings() const;
	};

	inline GUIFramework& GUIFramework::get()
	{
		static GUIFramework instance;

		return instance;
	}
}
