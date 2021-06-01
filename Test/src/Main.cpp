#include <iostream>

#include "SeparateWindow.h"

#pragma comment (lib, "GUIFramework.lib")

using namespace std;
using namespace gui_framework;

void test(const pair<wstring, wstring>& data, int x, int y)
{
	SeparateWindow window(data.first, data.second, x, y, 800, 600);

	MSG msg = {};

	while (GetMessageW(&msg, nullptr, NULL, NULL))
	{
		TranslateMessage(&msg);

		DispatchMessageW(&msg);
	}
}

int main(int argc, char** argv)
{
	string s;
	vector<pair<wstring, wstring>> windows =
	{
		{ L"First", L"First" },
		{ L"Second", L"Second" },
		{ L"Third", L"Third" },
		{ L"Fourth", L"Fourth" }
	};
	size_t i = 0;

	while (cin >> s)
	{
		if (i < windows.size())
		{
			thread(test, ref(windows[i++]), rand() % 1600, rand() % 900).detach();
		}
	}




	return 0;
}
