#pragma once

#include "pch.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief All settings for windows
		struct GUI_FRAMEWORK_API ComponentSettings
		{
			DWORD extendedStyles;
			DWORD styles;
			int x;
			int y;
			uint16_t width;
			uint16_t height;

			/// @brief Create settings for createing all windows
			/// @param styles Values from https://docs.microsoft.com/en-us/windows/win32/winmsg/window-styles
			/// (WS_OVERLAPPEDWINDOW style automatically applied if window is separate, WS_CHILDWINDOW style automatically applied if window has parent)
			/// @param x Top left corner x coordinate
			/// @param y Top left corner y coordinate
			/// @param extendedStyles Values from https://docs.microsoft.com/en-us/windows/win32/winmsg/extended-window-styles
			ComponentSettings(DWORD styles, int x, int y, uint16_t width, uint16_t height, DWORD extendedStyles = {});

			~ComponentSettings() = default;
		};
	}
}
