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
		DropDownListComboBox* list = new DropDownListComboBox(L"Drop", utility::ComponentSettings(0, 0, 400, 20), ptr);

		list->setBlockResize(true);

		list->addValue(L"First");
		list->addValue(L"Second");
		list->addValue(L"Third");
		list->addValue(L"Fourth");

		list->setOnSelectionChange([](BaseComboBox& ref) { wcout << ref.getValue(ref.getCurrentSelectionIndex()) << endl; });

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
