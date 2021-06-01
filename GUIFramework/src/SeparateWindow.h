#pragma once

#include "pch.h"

namespace gui_framework
{
	class SeparateWindow
	{
	protected:
		HWND handle;
		const std::wstring className;
		const std::wstring titleName;
		bool unregisterAfterDestroy;
		HINSTANCE module;

	public:
		/// @brief Create new separate window
		/// @param windowFunctionName Value that you pass in CREATE_DEFAULT_SEPARATE_WINDOW_FUNCTION macro
		/// @exception gui_framework::exceptions::AlreadyRegisteredClassNameException
		SeparateWindow(const std::wstring& className, const std::wstring& titleName, const std::string& windowFunctionName, int x, int y, int width, int height, int showMode = SW_SHOW, bool unregisterAfterDestroy = false);

		virtual LRESULT windowMessagesHandle(HWND handle, UINT msg, WPARAM wparam, LPARAM lparam);

		~SeparateWindow();
	};
}

#define CREATE_DEFAULT_SEPARATE_WINDOW_FUNCTION(className) extern "C" __declspec(dllexport) LRESULT className##WindowFunction (HWND handle, UINT msg, WPARAM wparam, LPARAM lparam)  \
	{ \
		static gui_framework::SeparateWindow* topLevelWindow = nullptr; \
		\
		switch(msg) \
		{ \
		case WM_DESTROY: \
			PostQuitMessage(0); \
				\
			return 0; \
			\
		case gui_framework::custom_window_messages::initTopLevelWindowPointer: \
			topLevelWindow = reinterpret_cast<gui_framework::SeparateWindow*>(wparam); \
				\
			return 0; \
			\
		default: \
			return topLevelWindow ? \
				topLevelWindow->windowMessagesHandle(handle, msg, wparam, lparam) : \
				DefWindowProcW(handle, msg, wparam, lparam); \
		} \
	}
