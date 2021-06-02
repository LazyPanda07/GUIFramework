#include "pch.h"
#include "GUIFramework.h"

using namespace std;

namespace gui_framework
{
	GUIFramework::GUIFramework()
	{
		InitCommonControlsEx(&comm);

		json::JSONParser json(ifstream(settings::settingsJSONFile.data()));
	}

	GUIFramework& GUIFramework::get()
	{
		static GUIFramework instance;

		return instance;
	}
}
