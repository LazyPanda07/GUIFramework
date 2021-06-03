#include <iostream>

#include "BaseComposites/BaseSeparateWindow.h"
#include "BaseComposites/BaseChildWindow.h"
#include "Components/StandardButton.h"
#include "Components/StandardEditControl.h"

#pragma comment (lib, "GUIFramework.lib")

using namespace std;

void test(const wstring& className, const wstring& title, const string& functionName, int x, int y)
{
	using namespace gui_framework;

	utility::ComponentSettings settings(WS_BORDER, x, y, 800, 600);
	utility::ComponentSettings insideWindowSettings(WS_BORDER, 100, 100, 400, 400);

	BaseSeparateWindow window(className, title, settings, functionName);
	BaseChildWindow* inside = new BaseChildWindow(L"Inside", L"Inside", insideWindowSettings, &window, "insideWindow");
	StandardButton* button = new StandardButton(L"Button", L"Кнопка", 100, 100, inside, 50, [&](WPARAM wparam, LPARAM lparam)
		{
			StandardEditControl* edit = dynamic_cast<StandardEditControl*>(window.findChild(L"Edit"));

			if (edit)
			{
				try
				{
					wcout << edit->getText() << endl;
				}
				catch (const std::exception& e)
				{
					cout << e.what() << endl;
				}
			}

			return 10;
		});
	StandardEditControl* edit = new StandardEditControl(L"Edit", 0, 0, &window);

	inside->addChild(button);

	window.addChild(inside);

	window.addChild(edit);

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
