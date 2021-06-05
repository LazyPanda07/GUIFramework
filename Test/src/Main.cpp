#include <iostream>

#include "Composites/SeparateWindow.h"
#include "Composites/ChildWindow.h"
#include "Components/Button.h"
#include "BaseComposites/BaseNonResizableComposite.h"

#pragma comment (lib, "GUIFramework.lib")

using namespace std;

void test(const wstring& className, const wstring& title, const string& functionName, int x, int y)
{
	using namespace gui_framework;

	utility::ComponentSettings settings(WS_BORDER, x, y, 800, 600);
	utility::ComponentSettings childWindowSettings(WS_BORDER, 100, 100, 400, 400);

	BaseNonResizableComposite window(className, title, settings, nullptr, functionName);
	ChildWindow* childWindow = new ChildWindow(className + L"Child", title + L"Child", childWindowSettings, &window, "childWindow");
	Button* button = new Button(L"ChildButton", L"Êíîïêà", 25, 25, childWindow, 1);
	
	button->setOnClick([&](WPARAM, LPARAM) -> LRESULT 
		{
			cout << "Click" << endl;

			return 0; 
		});

	window.addChild(childWindow);

	childWindow->setAutoResize(true);

	childWindow->addChild(button);

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
