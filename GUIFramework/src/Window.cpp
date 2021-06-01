#include "pch.h"
#include "Window.h"

using namespace std;

namespace gui_framework
{
	Window::Window(const wstring& className, const wstring& titleName, int x, int y, int width, int height, WNDPROC function)
	{
		WNDCLASSEXW classStruct = {};

		if (!GetClassInfoExW(GetModuleHandleW(nullptr), className.data(), &classStruct))
		{
			classStruct.cbSize = sizeof(WNDCLASSEXW);
			classStruct.lpszClassName = className.data();
			classStruct.lpfnWndProc = function;
			classStruct.hInstance = GetModuleHandleW(nullptr);
			classStruct.hbrBackground = HBRUSH(COLOR_WINDOW);

			RegisterClassExW(&classStruct);
		}

		handle = CreateWindowExW
		(
			WS_EX_APPWINDOW,
			className.data(),
			titleName.data(),
			WS_OVERLAPPEDWINDOW,
			x, y,
			width, height,
			nullptr,
			nullptr,
			GetModuleHandleW(nullptr),
			nullptr
		);

		ShowWindow(handle, SW_SHOW);
	}

	Window::~Window()
	{
		DestroyWindow(handle);
	}
}

