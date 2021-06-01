#include <iostream>

#include "SeparateWindow.h"

#pragma comment (lib, "GUIFramework.lib")

using namespace std;
using namespace gui_framework;

void test(const wstring& className, const wstring& title, const string& functionName, int x, int y)
{
	SeparateWindow window(className, title, functionName, x, y, 800, 600);

	MSG msg = {};

	while (GetMessageW(&msg, nullptr, NULL, NULL))
	{
		TranslateMessage(&msg);

		DispatchMessageW(&msg);
	}
}

CREATE_DEFAULT_SEPARATE_WINDOW_FUNCTION(mainWindow)

int main(int argc, char** argv)
{
	thread(test, L"Main window", L"Title", "mainWindow", 600, 450).detach();

	string s;

	while (cin >> s)
	{

	}




	return 0;
}
