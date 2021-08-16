#include <iostream>

#include "GUIFramework.h"
#include "Composites/ChildWindow.h"
#include "Utility/Holders/WindowHolder.h"
#include "Composites/SeparateWindow.h"
#include "Components/ComboBoxes/DropDownListComboBox.h"

#pragma comment (lib, "GUIFramework.lib")

using namespace std;

CREATE_DEFAULT_WINDOW_FUNCTION(main)

void test()
{
	using namespace gui_framework;

	utility::ComponentSettings settings(300, 200, 800, 600);

	try
	{
		WindowHolder holder(make_unique<SeparateWindow>(L"MainWindow", L"������� ����", settings, "main"));
		SeparateWindow* ptr = dynamic_cast<SeparateWindow*>(holder.get());

		DropDownListComboBox* list = new DropDownListComboBox(L"List", utility::ComponentSettings(0, 0, 300, 20), ptr);

		list->addValue(L"First");
		list->addValue(L"Second");

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
	try
	{
		gui_framework::GUIFramework::get();
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;

		return 0;
	}

	SetConsoleOutputCP(CP_UTF8);

	thread(test).detach();

	string s;

	while (cin >> s)
	{

	}

	return 0;
}
