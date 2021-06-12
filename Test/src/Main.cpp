#include <iostream>

#include "GUIFramework.h"
#include "Composites/SeparateWindow.h"
#include "Composites/ChildWindow.h"
#include "Components/RichEdit.h"
#include "Components/Button.h"

#pragma comment (lib, "GUIFramework.lib")

using namespace std;

void test(const wstring& className, const wstring& title, const string& functionName, int x, int y)
{
	using namespace gui_framework;

	utility::ComponentSettings settings(WS_BORDER, x, y, 800, 600);
	utility::ComponentSettings childWindowSettings(WS_BORDER, 600, 400, 200, 200);

	unique_ptr<SeparateWindow> mainWindow(make_unique<SeparateWindow>(className, title, settings, functionName));
	RichEdit* richEdit = new RichEdit(L"Rich", 0, 0, 150, 150, mainWindow.get(), true);
	Button* button = new Button(L"Button", L"Текст", 200, 25, mainWindow.get(), 1);

	ChildWindow* childWindow = new ChildWindow(L"ChildWindow", L"Child window", childWindowSettings, mainWindow.get(), "child");

	childWindow->addChild(new Button(L"Btn", L"Button", 0, 0, childWindow, 150));

	button->setOnClick([&](WPARAM, LPARAM) -> LRESULT
		{
			for (const auto& i : *mainWindow)
			{
				wcout << i->getWindowName() << endl;
			}

			return 0;
		});

	mainWindow->addChild(richEdit);

	mainWindow->addChild(childWindow);

	mainWindow->addChild(button);

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
