#include "pch.h"
#include "SeparateWindow.h"

#include "Exceptions/AlreadyRegisteredClassNameException.h"
#include "Exceptions/CantFindSeparateWindowFunctionException.h"

using namespace std;

namespace gui_framework
{
	SeparateWindow::SeparateWindow(const wstring& className, const wstring& titleName, const string& windowFunctionName, int x, int y, int width, int height, int showMode, bool unregisterAfterDestroy) :
		className(className),
		titleName(titleName),
		unregisterAfterDestroy(unregisterAfterDestroy),
		module(GetModuleHandleW(nullptr))
	{
		WNDCLASSEXW classStruct = {};

		if (!GetClassInfoExW(module, className.data(), &classStruct))
		{
			WNDPROC windowFunction = reinterpret_cast<WNDPROC>(GetProcAddress(nullptr, (windowFunctionName + "WindowFunction").data()));

			if (!windowFunction)
			{
				throw exceptions::CantFindSeparateWindowFunctionException(windowFunctionName + "WindowFunction");
			}

			classStruct.cbSize = sizeof(WNDCLASSEXW);
			classStruct.lpszClassName = className.data();
			classStruct.hInstance = module;
			classStruct.lpfnWndProc = windowFunction;
			classStruct.hbrBackground = HBRUSH(COLOR_WINDOW);

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

