#include <iostream>

#include "Composites/SeparateWindow.h"
#include "Composites/ChildWindow.h"
#include "Components/SimpleComboBox.h"
#include "Components/DropDownComboBox.h"
#include "Components/DropDownListComboBox.h"
#include "Components/Button.h"

#pragma comment (lib, "GUIFramework.lib")

using namespace std;

void test(const wstring& className, const wstring& title, const string& functionName, int x, int y)
{
	using namespace gui_framework;

	utility::ComponentSettings settings(WS_BORDER, x, y, 800, 600);

	unique_ptr<SeparateWindow> mainWindow(make_unique<SeparateWindow>(className, title, settings, functionName));
	BaseComboBox* comboBox = new DropDownListComboBox(L"Combo", 25, 25, 40, 120, mainWindow.get());
	Button* button = new Button(L"Button", L"Текст", 200, 25, mainWindow.get(), 1);

	button->setOnClick([&](WPARAM, LPARAM) -> LRESULT
		{
			cout << comboBox->getActualHeight() << endl;

			return 0;
		});

	comboBox->addValue(L"First");
	comboBox->addValue(L"Second");
	comboBox->addValue(L"Third");

	mainWindow->addChild(comboBox);

	mainWindow->addChild(button);

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
