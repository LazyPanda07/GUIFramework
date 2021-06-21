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
				GetWindowLongPtrW(handle, GWL_STYLE) & ~styleToRemove
			);
		}

		void setBackgroundColor(HWND handle, uint8_t red, uint8_t green, uint8_t blue)
		{
			SetWindowLongPtrW
			(
				handle,
				GCLP_HBRBACKGROUND,
				reinterpret_cast<LONG_PTR>(CreateSolidBrush(RGB(red, green, blue)))
			);
		}
	}
}
