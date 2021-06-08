#include "pch.h"
#include "Utility.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		void unregisterClass(const wstring& className)
		{
			UnregisterClassW(className.data(), GetModuleHandleW(nullptr));
		}

		void appendStyle(HWND handle, LONG_PTR newStyle)
		{
			SetWindowLongPtrW
			(
				handle,
				GWL_STYLE,
				GetWindowLongPtrW(handle, GWL_STYLE) | newStyle
			);
		}

		void removeStyle(HWND handle, LONG_PTR styleToRemove)
		{
			SetWindowLongPtrW
			(
				handle,
				GWL_STYLE,
				GetWindowLongPtrW(handle, GWL_STYLE) ^ styleToRemove
			);
		}
	}
}
