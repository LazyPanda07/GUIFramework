#include <iostream>

#include "GUIFramework.h"
#include "Composites/SeparateWindow.h"

#pragma comment (lib, "GUIFramework.lib")

using namespace std;

void test(const wstring& className, const wstring& title, const string& functionName, int x, int y)
{
	using namespace gui_framework;

	utility::ComponentSettings settings(WS_BORDER, x, y, 800, 600);

	unique_ptr<SeparateWindow> mainWindow(make_unique<SeparateWindow>(className, title, settings, functionName));

	mainWindow->setExitMode(BaseComponent::exitMode::quit);

	unique_ptr<Menu>& menu = mainWindow->createMainMenu(L"Main menu");

	MSG msg = {};

	while (GetMessageW(&msg, nullptr, NULL, NULL))
	{
		TranslateMessage(&msg);

		DispatchMessageW(&msg);
	}
}

CREATE_DEFAULT_WINDOW_FUNCTION(main)

CREATE_DEFAULT_WINDOW_FUNCTION(child)

int main(int argc, char** argv)
{
	setlocale(LC_CTYPE, "RU");

	gui_framework::GUIFramework::get();

	thread(test, L"Main window", L"Title", "main", 300, 200).detach();

	string s;

	while (cin >> s)
	{

	}




	return 0;
}
