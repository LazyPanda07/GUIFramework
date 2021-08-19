#include <iostream>

#include "GUIFramework.h"
#include "Utility/Holders/WindowHolder.h"
#include "Components/RichEdit.h"
#include "Components/StaticControl.h"
#include "Composites/SeparateWindow.h"
#include "Components/ListViews/ListTextIconListView.h"
#include "MenuItems/MenuItem.h"
#include "MenuItems/DropDownMenuItem.h"
#include "Composites/ChildWindow.h"
#include "Composites/DialogBox.h"
#include "Components/Buttons/ImageButton.h"

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
		WindowHolder holder(make_unique<SeparateWindow>(L"MainWindow", L"������� ����", settings, "main"));
		SeparateWindow* ptr = dynamic_cast<SeparateWindow*>(holder.get());
		// ChildWindow* child = new ChildWindow(L"ChildWindow", L"Child window name", utility::ComponentSettings(600, 400, 200, 200), ptr, "child");
		// ListTextIconListView* list = new ListTextIconListView(L"List", utility::ComponentSettings(0, 0, 300, 200), ptr, utility::iconListViewType::smallIcon);
		// RichEdit* richEdit = new RichEdit(L"RichEdit", utility::ComponentSettings(300, 0, 300, 200), ptr, true);
		// new StaticControl(L"Text", L"����� ������ ChildWindow", 0, 0, child);
		// 
		// richEdit->setAutoURLDetect(true);
		// 
		// richEdit->addUrlDetectEvent(BaseRichEdit::urlDetectEvent::mouseMove, "testEdit", "callbacks");
		// 
		// list->addTextIconItem(L"First", "assets/icon.ico");
		// 
		// list->addTextIconItem(L"Second", "assets/another_icon.ico");

		ImageButton* button = new ImageButton(L"Image", "assets/icon.ico", ImageButton::drawingType::textAndImage, 32, 32, 0, 0, ptr);

		button->setText(L"Text");

		ptr->setExitMode(BaseComponent::exitMode::quit);

		ptr->setLargeIcon(R"(assets\icon.ico)");

		// thread([ptr]() { this_thread::sleep_for(2s); ofstream("test.json") << *ptr << endl; }).detach();

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
