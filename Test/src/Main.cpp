#include <iostream>

#include "GUIFramework.h"
#include "WindowHolder.h"
#include "Composites/SeparateWindow.h"

#pragma comment (lib, "GUIFramework.lib")

using namespace std;

void test()
{
	using namespace gui_framework;

	utility::ComponentSettings settings(WS_BORDER, 300, 200, 800, 600);

	WindowHolder holder(make_unique<SeparateWindow>(L"MainWindow", L"Главное окно", settings, "main"));

	holder.get()->setExitMode(BaseComponent::exitMode::quit);

	holder.runMainLoop();
}

CREATE_DEFAULT_WINDOW_FUNCTION(main)

int main(int argc, char** argv)
{
	gui_framework::GUIFramework::get();

	thread(test).detach();

	string s;

	while (cin >> s)
	{

	}

	return 0;
}
