#include <iostream>

#include "GUIFramework.h"
#include "WindowHolder.h"
#include "BaseComponents/StandardComponents/ListView/BaseReportTextListView.h"
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
		BaseReportTextListView* list = new BaseReportTextListView(L"List", utility::ComponentSettings(WS_BORDER, 0, 0, 600, 400), ptr);

		list->addTextItem(L"First column");

		list->addTextItem(L"Second column");

		list->addTextItem(L"Third column");

		list->addTextItem(L"First subitem", 0, 2);

		list->addTextItem(L"Third subitem", 2, 1);

		list->addTextItem(L"Second suibtem", 1, 0);

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
