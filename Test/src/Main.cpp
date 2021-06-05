#include <iostream>

#include "Composites/SeparateWindow.h"
#include "Composites/ChildWindow.h"
#include "Components/Button.h"
#include "Components/EditControl.h"
#include "Components/StaticControl.h"

#pragma comment (lib, "GUIFramework.lib")

using namespace std;

void test(const wstring& className, const wstring& title, const string& functionName, int x, int y)
{
	using namespace gui_framework;

	utility::ComponentSettings settings(WS_BORDER, x, y, 800, 600);
	utility::ComponentSettings childWindowSettings(WS_BORDER, 100, 100, 400, 400);

	SeparateWindow window(className, title, settings, functionName);
	ChildWindow* childWindow = new ChildWindow(className + L"Child", title + L"Child", childWindowSettings, &window, "childWindow");
	
	window.addChild(childWindow);

	childWindow->addChild(new Button(L"ChildButton", L"Кнопка внутри", 25, 25, childWindow, 1, [&](WPARAM, LPARAM) ->LRESULT { wcout << childWindow->getWindowName() << endl; return 0; }));

	MSG msg = {};

	while (GetMessageW(&msg, nullptr, NULL, NULL))
	{
		TranslateMessage(&msg);

		DispatchMessageW(&msg);
	}
}

CREATE_DEFAULT_WINDOW_FUNCTION(mainWindow)

CREATE_DEFAULT_WINDOW_FUNCTION(childWindow)

int main(int argc, char** argv)
{
	setlocale(LC_CTYPE, "RU");

	thread(test, L"Main window", L"Title", "mainWindow", 300, 200).detach();

	string s;

	while (cin >> s)
	{

	}




	return 0;
}
