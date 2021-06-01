#include <iostream>

#include "BaseComposites/BaseSeparateWindow.h"
#include "BaseComposites/BaseChildWindow.h"
#include "Components/StandardButton.h"

#pragma comment (lib, "GUIFramework.lib")

using namespace std;
using namespace gui_framework;

void test(const wstring& className, const wstring& title, const string& functionName, int x, int y)
{
	utility::ComponentSettings settings(WS_BORDER, x, y, 800, 600);
	utility::ComponentSettings insideWindowSettings(WS_BORDER, 100, 100, 400, 400);
	
	BaseSeparateWindow window(className, title, settings, functionName);
	BaseChildWindow* inside = new BaseChildWindow(L"Inside", L"Inside", insideWindowSettings, &window, "insideWindow");
	StandardButton* button = new StandardButton(L"Button", insideWindowSettings, inside, 50, [](WPARAM wparam, LPARAM lparam) { cout << "Rofl" << endl; return 10; });
	
	inside->addChild(button);

	window.addChild(inside);

	MSG msg = {};

	while (GetMessageW(&msg, nullptr, NULL, NULL))
	{
		TranslateMessage(&msg);

		DispatchMessageW(&msg);
	}
}

CREATE_DEFAULT_WINDOW_FUNCTION(mainWindow)

CREATE_DEFAULT_WINDOW_FUNCTION(insideWindow)

int main(int argc, char** argv)
{
	thread(test, L"Main window", L"Title", "mainWindow", 300, 200).detach();

	string s;

	while (cin >> s)
	{

	}




	return 0;
}
