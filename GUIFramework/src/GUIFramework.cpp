#include "pch.h"
#include "GUIFramework.h"

using namespace std;

namespace gui_framework
{
	GUIFramework::GUIFramework() :
		msftEditModule(LoadLibraryW(libraries::msftEditLibrary.data()))
	{
		InitCommonControlsEx(&comm);

		json::JSONParser json(ifstream(settings::settingsJSONFile.data()));
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
}
