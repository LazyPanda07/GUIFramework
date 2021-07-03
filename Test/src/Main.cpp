#include <iostream>

#include "GUIFramework.h"
#include "WindowHolder.h"
#include "BaseComponents/StandardComponents/ListView/BaseIconListView.h"
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
		BaseIconListView* list = new BaseIconListView(L"List", utility::ComponentSettings(WS_BORDER, 0, 0, 200, 100), ptr, utility::iconListViewType::icon, 32, 32);

		list->addIconItem(R"(assets\icon.ico)");

		list->addIconItem(R"(assets\icon.ico)");

		list->addIconItem(R"(assets\icon.ico)");

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
