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
	// RichEdit* richEdit = new RichEdit(L"Rich", 0, 0, 150, 150, mainWindow.get(), true);
	vector<function<LRESULT(WPARAM, LPARAM)>> callbacks =
	{
		[](WPARAM, LPARAM) -> LRESULT { cout << "First" << endl; return 0; },
		[](WPARAM, LPARAM) -> LRESULT { cout << "Second" << endl; return 0; },
		[](WPARAM, LPARAM) -> LRESULT { cout << "Third" << endl; return 0; }
	};
	vector<pair<wstring, wstring>> names =
	{
		{ L"First button", L"Ито жи первая кнопка" },
		{ L"Second button", L"Ито жи вторая кнопка" },
		{ L"Third button", L"Ито жи третья кнопка" },
	};

	for (size_t i = 0; i < 3; i++)
	{
		Button* button = new Button(names[i].first, names[i].second, 0, 20 * i, mainWindow.get(), callbacks[i]);
	}

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
