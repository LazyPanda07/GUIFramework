#include "pch.h"
#include "GUIFramework.h"

using namespace std;

namespace gui_framework
{
	GUIFramework::GUIFramework() :
		jsonSettings(ifstream(settings::settingsJSONFile.data())),
		threadPool(jsonSettings.get<int64_t>(settings::threadsCountSetting)),
		msftEditModule(LoadLibraryW(libraries::msftEditLibrary.data()))
	{
		InitCommonControlsEx(&comm);
	}

	GUIFramework::~GUIFramework()
	{
		FreeLibrary(msftEditModule);
	}

	GUIFramework& GUIFramework::get()
	{
		static GUIFramework instance;

		return instance;
	}

	void GUIFramework::addTask(const function<void()>& task, const function<void()>& callback)
	{
		threadPool.addTask(task, callback);
	}

	void GUIFramework::addTask(function<void()>&& task, const function<void()>& callback)
	{
		threadPool.addTask(move(task), callback);
	}

	const json::JSONParser& GUIFramework::getJSONSettings() const
	{
		return jsonSettings;
	}
}
