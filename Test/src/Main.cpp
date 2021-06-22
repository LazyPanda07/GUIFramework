#include <iostream>

#include "GUIFramework.h"
#include "WindowHolder.h"
#include "Components/Button.h"
#include "Components/EditControl.h"
#include "Components/StaticControl.h"
#include "Components/RichEdit.h"
#include "Components/SimpleComboBox.h"
#include "Components/DropDownComboBox.h"
#include "Components/DropDownListComboBox.h"
#include "Components/ListBox.h"
#include "Composites/SeparateWindow.h"

#pragma comment (lib, "GUIFramework.lib")

using namespace std;

CREATE_DEFAULT_WINDOW_FUNCTION(main)

void test()
{
	using namespace gui_framework;

	utility::ComponentSettings settings(WS_BORDER, 300, 200, 800, 600);

	try
	{
		WindowHolder holder(make_unique<SeparateWindow>(L"MainWindow", L"Главное окно", settings, "main"));

		SeparateWindow* ptr = dynamic_cast<SeparateWindow*>(holder.get());

		ptr->setExitMode(BaseComponent::exitMode::quit);

		ptr->setLargeIcon(R"(assets\icon.ico)");

		BaseComboBox* simpleComboBox = new SimpleComboBox(L"ComboBox", 200, 0, 200, 80, ptr);

		BaseComboBox* dropDownComboBox = new DropDownComboBox(L"DropDownBox", 200, 150, 200, 80, ptr);

		BaseComboBox* dropDownListComboBox = new DropDownListComboBox(L"DropDownListBox", 200, 300, 200, 80, ptr);

		simpleComboBox->addValue(L"First combo box");
		simpleComboBox->addValue(L"Second combo box");

		dropDownComboBox->addValue(L"First drop down combo box");
		dropDownComboBox->addValue(L"Second drop down combo box");

		dropDownListComboBox->addValue(L"First drop down list combo box");
		dropDownListComboBox->addValue(L"Second drop down list combo box");

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

	thread(test).detach();

	string s;

	while (cin >> s)
	{

	}

	return 0;
}
