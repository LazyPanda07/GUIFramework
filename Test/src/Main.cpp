#include <iostream>

#include "GUIFramework.h"
#include "Components/StaticControl.h"
#include "Components/Buttons/Button.h"
#include "Composites/ChildWindow.h"
#include "Utility/Holders/WindowHolder.h"
#include "Composites/SeparateWindow.h"
#include "MenuItems/MenuItem.h"
#include "MenuItems/DropDownMenuItem.h"

#pragma comment (lib, "GUIFramework.lib")

using namespace std;

CREATE_DEFAULT_WINDOW_FUNCTION(main)

CREATE_DEFAULT_WINDOW_FUNCTION(child)

void createMenus(gui_framework::SeparateWindow* ptr)
{
	using namespace gui_framework;

	unique_ptr<Menu>& menu = ptr->createMainMenu(L"MainMenu");

	menu->addMenuItem(make_unique<MenuItem>(L"First", []() { cout << "First" << endl; }));

	Menu& popup = ptr->addPopupMenu(L"Second");

	popup.addMenuItem(make_unique<MenuItem>(L"Inside", []() { cout << "Inside" << endl; }));

	menu->addMenuItem(make_unique<DropDownMenuItem>(L"Popup", popup.getHandle()));
}

void test()
{
	using namespace gui_framework;

	utility::ComponentSettings settings(300, 200, 800, 600);

	try
	{
		WindowHolder holder(make_unique<SeparateWindow>(L"MainWindow", L"Главное окно", settings, "main"));
		SeparateWindow* ptr = dynamic_cast<SeparateWindow*>(holder.get());
		new StaticControl(L"Текст", L"Текст в окне", 50, 50, ptr);

		createMenus(ptr);

		cout << *ptr << endl;

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
