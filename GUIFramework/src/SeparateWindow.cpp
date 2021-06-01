#include "pch.h"
#include "SeparateWindow.h"

using namespace std;

namespace gui_framework
{
	SeparateWindow* windowPointer = nullptr;

	LRESULT SeparateWindow::windowFunction(HWND handle, UINT msg, WPARAM wparam, LPARAM lparam)
	{
		switch (msg)
		{
		case WM_DESTROY:
			PostQuitMessage(0);

			return 0;

		default:
			return windowPointer ?
				windowPointer->windowMessagesHandle(handle, msg, wparam, lparam) :
				DefWindowProcW(handle, msg, wparam, lparam);
		}
	}

	SeparateWindow::SeparateWindow(const wstring& className, const wstring& titleName, int x, int y, int width, int height, int showMode, bool unregisterAfterDestroy) :
		className(className),
		titleName(titleName),
		unregisterAfterDestroy(unregisterAfterDestroy),
		module(GetModuleHandleW(nullptr))
	{
		WNDCLASSEXW classStruct = {};

		if (!GetClassInfoExW(module, className.data(), &classStruct))
		{
			classStruct.cbSize = sizeof(WNDCLASSEXW);
			classStruct.lpszClassName = className.data();
			classStruct.lpfnWndProc = windowFunction;
			classStruct.hInstance = module;
			classStruct.hbrBackground = HBRUSH(COLOR_WINDOW);

			RegisterClassExW(&classStruct);
		}

		windowPointer = this;

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
			module,
			nullptr
		);

		ShowWindow(handle, showMode);
	}

	LRESULT SeparateWindow::windowMessagesHandle(HWND handle, UINT msg, WPARAM wparam, LPARAM lparam)
	{
		return DefWindowProcW(handle, msg, wparam, lparam);
	}

	SeparateWindow::~SeparateWindow()
	{
		DestroyWindow(handle);

		if (unregisterAfterDestroy)
		{
			UnregisterClassW
			(
				className.data(),
				module
			);
		}
	}
}

