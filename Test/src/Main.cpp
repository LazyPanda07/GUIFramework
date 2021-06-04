#include <iostream>

#include "BaseComposites/BaseSeparateWindow.h"
#include "BaseComposites/BaseChildWindow.h"
#include "Components/Button.h"
#include "Components/EditControl.h"
#include "Components/StaticControl.h"

#pragma comment (lib, "GUIFramework.lib")

using namespace std;

void test(const wstring& className, const wstring& title, const string& functionName, int x, int y)
{
	using namespace gui_framework;

	utility::ComponentSettings settings(WS_BORDER, x, y, 800, 600);
	utility::ComponentSettings insideWindowSettings(WS_BORDER, 100, 100, 400, 400);

	BaseSeparateWindow window(className, title, settings, functionName);
	
	window.addChild(new StaticControl(L"Message", L"��� �������� ���������", 0, 0, &window));

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
