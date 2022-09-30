#pragma once

#include "Core.h"
#include "Interfaces/Styles/IStyles.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief All settings for windows
		struct GUI_FRAMEWORK_API ComponentSettings
		{
			int x;
			int y;
			uint16_t width;
			uint16_t height;
			interfaces::IStyles styles;
			std::vector<std::string> localizationKeys;

			ComponentSettings() = default;

			/// @brief Create settings for createing all windows
			/// @param x Top left corner x coordinate
			/// @param y Top left corner y coordinate
			/// @param width 
			/// @param height 
			/// @param localizationKeys Optional parameter for localization possibilities
			ComponentSettings(int x, int y, uint16_t width, uint16_t height, const std::vector<std::string>& localizationKeys = {});

			~ComponentSettings() = default;
		};
	}
}
