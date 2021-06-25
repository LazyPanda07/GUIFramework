#include <iostream>

#include "GUIFramework.h"
#include "WindowHolder.h"
#include "BaseComponents/StandardComponents/ListView/BaseTextListView.h"
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
		BaseTextListView* list = new BaseTextListView(L"List", utility::ComponentSettings(WS_BORDER, 0, 0, 200, 100), ptr);

		LVITEMW item = {};

		item.mask = LVIF_TEXT;
		item.iItem = 0;
		item.pszText = const_cast<wchar_t*>(L"First");
		item.cchTextMax = 6;

		SendMessageW(list->getHandle(), LVM_ISITEMVISIBLE, SendMessageW(list->getHandle(), LVM_INSERTITEM, NULL, reinterpret_cast<LPARAM>(&item)), NULL);

		item.pszText = const_cast<wchar_t*>(L"Second");
		item.cchTextMax = 7;

		SendMessageW(list->getHandle(), LVM_ISITEMVISIBLE, SendMessageW(list->getHandle(), LVM_INSERTITEM, NULL, reinterpret_cast<LPARAM>(&item)), NULL);

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

	thread(test).detach();

	string s;

	while (cin >> s)
	{

	}

	return 0;
}
