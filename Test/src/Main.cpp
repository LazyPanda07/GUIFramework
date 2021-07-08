#include <iostream>

#include "GUIFramework.h"
#include "WindowHolder.h"
#include "Composites/DialogBox.h"
#include "Components/InfiniteProgressBar.h"
#include "Composites/SeparateWindow.h"

#pragma comment (lib, "GUIFramework.lib")

using namespace std;

CREATE_DEFAULT_WINDOW_FUNCTION(main)

CREATE_DEFAULT_WINDOW_FUNCTION(dialog)

void test()
{
	using namespace gui_framework;

	utility::ComponentSettings settings(WS_BORDER, 300, 200, 800, 600);

	try
	{
		WindowHolder holder(make_unique<SeparateWindow>(L"MainWindow", L"Главное окно", settings, "main"));

		SeparateWindow* ptr = dynamic_cast<SeparateWindow*>(holder.get());
		DialogBox* dialog = DialogBox::DialogBoxBuilder(L"MainDialog", L"QWE", 100, 100, "dialog").addComponent<InfiniteProgressBar>(L"Progress", 200, 10, DialogBox::DialogBoxBuilder::alignment::center).build();

		dialog->show();

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
