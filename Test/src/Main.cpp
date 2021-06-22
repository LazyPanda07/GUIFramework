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

int main(int argc, char** argv)
{
	gui_framework::GUIFramework::get();

	using namespace gui_framework;

	utility::ComponentSettings settings(WS_BORDER, 300, 200, 800, 600);

	try
	{
		WindowHolder holder(make_unique<SeparateWindow>(L"MainWindow", L"Главное окно", settings, "main"));

		SeparateWindow* ptr = dynamic_cast<SeparateWindow*>(holder.get());

		ptr->setExitMode(BaseComponent::exitMode::quit);

		ptr->setLargeIcon(R"(assets\icon.ico)");

		Button* button = new Button(L"Button", L"Текст", 0, 0, ptr, [](WPARAM, LPARAM) { cout << "Click" << endl; return 0; });
		
		EditControl* editControl = new EditControl(L"Edit", 0, 20, ptr);
		
		StaticControl* staticControl = new StaticControl(L"Static", L"Текст", 0, 40, ptr);
		
		RichEdit* richEdit = new RichEdit(L"Rich", 0, 80, 200, 40, ptr, true);
		
		BaseComboBox* simpleComboBox = new SimpleComboBox(L"ComboBox", 200, 0, 200, 80, ptr);
		
		BaseComboBox* dropDownComboBox = new DropDownComboBox(L"DropDownBox", 200, 150, 200, 80, ptr);
		
		BaseComboBox* dropDownListComboBox = new DropDownListComboBox(L"DropDownListBox", 200, 300, 200, 80, ptr);
		
		ListBox* listBox = new ListBox(L"ListBox", 400, 0, 200, 80, ptr);
		
		simpleComboBox->setAutoResize(false);
		listBox->setAutoResize(false);
		
		simpleComboBox->addValue(L"First combo box");
		simpleComboBox->addValue(L"Second combo box");
		
		dropDownComboBox->addValue(L"First drop down combo box");
		dropDownComboBox->addValue(L"Second drop down combo box");
		
		dropDownListComboBox->addValue(L"First drop down list combo box");
		dropDownListComboBox->addValue(L"Second drop down list combo box");
		
		listBox->addValue(L"First list box");
		listBox->addValue(L"Second list box");
		
		vector<BaseComponent*> components =
		{
			button,
			editControl,
			staticControl,
			richEdit,
			simpleComboBox,
			listBox,
			dropDownComboBox,
			dropDownListComboBox
		};
		
		srand(time(nullptr));
		
		for (const auto& i : components)
		{
			i->setBackgroundColor(rand() % 255, rand() % 255, rand() % 255);
		}

		holder.runMainLoop();
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}
