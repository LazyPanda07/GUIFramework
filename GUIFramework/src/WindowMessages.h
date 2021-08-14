#pragma once

#include "pch.h"

namespace gui_framework
{
	namespace custom_window_messages
	{
		/// @brief WPARAM contains pointer to BaseComponent
		inline constexpr int initTopLevelWindowPointer = 52430;

		/// @brief Set to nullptr topLevelWindow for recreating window with same window class name
		inline constexpr int deinitTopLevelWindowPointer = 52431;
	}
}
