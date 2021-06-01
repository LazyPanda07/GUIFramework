#include "pch.h"
#include "SeparateWindow.h"

#include "Exceptions/AlreadyRegisteredClassNameException.h"

using namespace std;

namespace gui_framework
{
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
			classStruct.hInstance = module;
			classStruct.hbrBackground = HBRUSH(COLOR_WINDOW);

			classStruct.lpfnWndProc = [](HWND handle, UINT msg, WPARAM wparam, LPARAM lparam) -> LRESULT
			{
				static SeparateWindow* topLevelWindow = nullptr;

				switch (msg)
				{
				case WM_DESTROY:
					PostQuitMessage(0);

					return 0;

				case custom_window_messages::initTopLevelWindowPointer:
					topLevelWindow = reinterpret_cast<SeparateWindow*>(wparam);

					return 0;

				default:
					return topLevelWindow ?
						topLevelWindow->windowMessagesHandle(handle, msg, wparam, lparam) :
						DefWindowProcW(handle, msg, wparam, lparam);
				}
			};

			RegisterClassExW(&classStruct);
		}
		else
		{
			throw exceptions::AlreadyRegisteredclassNameException();
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
			module,
			nullptr
		);

		SendMessageW(handle, custom_window_messages::initTopLevelWindowPointer, reinterpret_cast<WPARAM>(this), NULL);

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

