#include <iostream>

#include "GUIFramework.h"
#include "Components/StaticControl.h"
#include "Components/Buttons/Button.h"
#include "Components/ComboBoxes/DropDownListComboBox.h"
#include "Composites/ChildWindow.h"
#include "Utility/Holders/WindowHolder.h"
#include "Composites/SeparateWindow.h"

#pragma comment (lib, "GUIFramework.lib")

using namespace std;

CREATE_DEFAULT_WINDOW_FUNCTION(main)

CREATE_DEFAULT_WINDOW_FUNCTION(child)

void test()
{
	using namespace gui_framework;

	utility::ComponentSettings settings(300, 200, 800, 600);

	try
	{
		WindowHolder holder(make_unique<SeparateWindow>(L"MainWindow", L"Главное окно", settings, "main"));
		SeparateWindow* ptr = dynamic_cast<SeparateWindow*>(holder.get());

		ptr->setExitMode(BaseComponent::exitMode::quit);

		ptr->setLargeIcon(R"(assets\icon.ico)");

		holder.runMainLoop();
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
}

int main(int argc, char** argv)
{
	gui_framework::GUIFramework::get();

	SetConsoleOutputCP(CP_UTF8);

	thread(test).detach();

	string s;

	while (cin >> s)
	{

	}

	return 0;
}
