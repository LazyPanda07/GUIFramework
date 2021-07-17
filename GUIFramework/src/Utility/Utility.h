#pragma once

#include "pch.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief Unregister class that is used in SeparateWindow, ChildWindow, DialogBox, GroupBox
		/// @param className 
		GUI_FRAMEWORK_API_FUNCTION void unregisterClass(const std::wstring& className);

		/// @brief Append WinAPI style
		/// @param handle 
		/// @param newStyle 
		GUI_FRAMEWORK_API_FUNCTION void appendStyle(HWND handle, LONG_PTR newStyle);

		/// @brief Remove WinAPI style
		/// @param handle 
		/// @param styleToRemove 
		GUI_FRAMEWORK_API_FUNCTION void removeStyle(HWND handle, LONG_PTR styleToRemove);
	}
}
