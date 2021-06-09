#pragma once

#include "pch.h"

#pragma comment (lib, "Comctl32.lib")

#pragma comment (lib, "JSON.lib")
#pragma comment (lib, "ThreadPool.lib")

namespace gui_framework
{
	/// @brief Singleton with GUIFramework settings
	class GUIFramework
	{
	private:
		json::JSONParser jsonSettings;
		threading::ThreadPool threadPool;
		INITCOMMONCONTROLSEX comm;
		HMODULE msftEditModule;

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

		const json::JSONParser& getJSONSettings() const;
	};
}
