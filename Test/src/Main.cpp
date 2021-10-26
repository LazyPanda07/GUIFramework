#include <iostream>

#include "GUIFramework.h"
#include "Utility/Holders/WindowHolder.h"
#include "MenuItems/MenuItem.h"
#include "MenuItems/DropDownMenuItem.h"
#include "ComponentsHeader.h"
#include "CompositesHeader.h"

#include "Deserialization/Recreator.h"

#pragma comment (lib, "GUIFramework.lib")

using namespace std;

CREATE_DEFAULT_WINDOW_FUNCTION(main)

CREATE_DEFAULT_WINDOW_FUNCTION(child)

void standard()
{
	using namespace gui_framework;

	utility::ComponentSettings settings(300, 200, 800, 600);

	try
	{
		WindowHolder holder(make_unique<SeparateWindow>(L"MainWindow", L"������� ����", settings, "main"));
		SeparateWindow* ptr = dynamic_cast<SeparateWindow*>(holder.get());
		ChildWindow* child = new ChildWindow(L"ChildWindow", L"Child window name", utility::ComponentSettings(600, 400, 200, 200), ptr, "child");

		auto& menu = ptr->createMainMenu(L"Menu");

		auto& popup = ptr->addPopupMenu(L"Popup");

		auto& insidePopup = ptr->addPopupMenu(L"InsidePopup");

		insidePopup.addMenuItem(make_unique<MenuItem>(L"Second", "test", "callbacks"));

		popup.addMenuItem(make_unique<MenuItem>(L"First", "test", "callbacks"));

		menu->addMenuItem(make_unique<MenuItem>(L"Third", "test", "callbacks"));

		popup.addMenuItem(make_unique<DropDownMenuItem>(L"Inside popup", insidePopup.getHandle()));

		menu->addMenuItem(make_unique<DropDownMenuItem>(L"PopupMenu", popup.getHandle()));

		ptr->setExitMode(BaseComposite::exitMode::quit);
		
		ptr->setLargeIcon(R"(assets\icon.ico)");

		thread([ptr]() { this_thread::sleep_for(2s); ofstream("test.json") << ptr->getStructure(); }).detach();

		holder.runMainLoop();
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
}

void test()
{
	using namespace gui_framework;

	try
	{
		Recreator recreator(filesystem::path("test.json"));
		WindowHolder holder(recreator.deserialize());

		holder.runMainLoop();
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;

		exit(0);
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
