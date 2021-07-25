#include <iostream>

#include "GUIFramework.h"
#include "Components/StaticControl.h"
#include "Components/Buttons/Button.h"
#include "Composites/ChildWindow.h"
#include "Utility/Holders/WindowHolder.h"
#include "Composites/SeparateWindow.h"

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
		WindowHolder holder(make_unique<SeparateWindow>(L"MainWindow", L"Главное окно", settings, "main"));
		SeparateWindow* ptr = dynamic_cast<SeparateWindow*>(holder.get());
		new StaticControl(L"Текст", L"Текст в окне", 50, 50, ptr);
		new Button(L"Pure button", L"Some text on button", 500, 20, ptr, []() { cout << "Nice" << endl; });

		ChildWindow* window = new ChildWindow(L"Child class", L"Nested class", utility::ComponentSettings(50, 300, 200, 200), ptr, "child");

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
