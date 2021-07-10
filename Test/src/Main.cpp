#include <iostream>

#include "GUIFramework.h"
#include "WindowHolder.h"
#include "Components/GroupBox.h"
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
		GroupBox* box = new GroupBox(L"TestBox", L"Box", 0, 0, 400, 400, ptr, "first");

		box->addRadioButton(L"First", L"First", 0, 0, 200, 20, []() { cout << "First" << endl; });

		box->addRadioButton(L"Second", L"Second", 0, 20, 200, 20, []() { cout << "Second" << endl; });

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
