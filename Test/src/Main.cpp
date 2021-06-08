#include <iostream>

#include "Composites/SeparateWindow.h"
#include "Composites/ChildWindow.h"
#include "Components/ListBox.h"
#include "Components/MultipleSelectListBox.h"
#include "Components/Button.h"

#pragma comment (lib, "GUIFramework.lib")

using namespace std;

void test(const wstring& className, const wstring& title, const string& functionName, int x, int y)
{
	using namespace gui_framework;

	utility::ComponentSettings settings(WS_BORDER, x, y, 800, 600);

	unique_ptr<SeparateWindow> mainWindow(make_unique<SeparateWindow>(className, title, settings, functionName));
	BaseListBox* listBox = new ListBox(L"List", 25, 25, 200, 200, mainWindow.get());
	Button* button = new Button(L"Button", L"Текст", 200, 25, mainWindow.get(), 1);

	button->setOnClick([&](WPARAM, LPARAM) -> LRESULT
		{
			

			return 0;
		});

	UpdateWindow(listBox->getHandle());

	listBox->addValue(L"First");
	listBox->addValue(L"Second");
	listBox->addValue(L"Third");

	mainWindow->addChild(listBox);

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
