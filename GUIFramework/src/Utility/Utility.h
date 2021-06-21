#pragma once

#include "pch.h"

namespace gui_framework
{
	namespace utility
	{
		GUI_FRAMEWORK_API_FUNCTION void unregisterClass(const std::wstring& className);

		GUI_FRAMEWORK_API_FUNCTION void appendStyle(HWND handle, LONG_PTR newStyle);

		GUI_FRAMEWORK_API_FUNCTION void removeStyle(HWND handle, LONG_PTR styleToRemove);

		GUI_FRAMEWORK_API_FUNCTION void setBackgroundColor(HWND handle, uint8_t red, uint8_t green, uint8_t blue);
	}
}
