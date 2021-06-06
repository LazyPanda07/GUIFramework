#include <iostream>

#include "Composites/SeparateWindow.h"
#include "Composites/ChildWindow.h"
#include "Components/SimpleComboBox.h"

#pragma comment (lib, "GUIFramework.lib")

using namespace std;

void test(const wstring& className, const wstring& title, const string& functionName, int x, int y)
{
	using namespace gui_framework;

	utility::ComponentSettings settings(WS_BORDER, x, y, 800, 600);

	unique_ptr<SeparateWindow> mainWindow(make_unique<SeparateWindow>(className, title, settings, functionName));
	SimpleComboBox* comboBox = new SimpleComboBox(L"Combo", 25, 25, 40, 120, mainWindow.get());

	comboBox->addValue(L"First");
	comboBox->addValue(L"Second");
	comboBox->addValue(L"Third");

	mainWindow->addChild(comboBox);

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
