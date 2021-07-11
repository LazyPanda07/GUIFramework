#pragma once

#include "Utility/Holders/BaseLoadableHolder.h"
#include "BaseComposites/StandardComposites/BaseWindow.h"

namespace gui_framework
{
	namespace utility
	{
		namespace paint
		{
			/// @brief Draw image from holder
			/// @param window 
			/// @param holder 
			/// @param x 
			/// @param y 
			/// @param index Internal index of image
			/// @param width Zero means take entire image width
			/// @param height Zero means take entire image height
			/// @return 
			/// @exception std::out_of_range Wrong index
			GUI_FRAMEWORK_API_FUNCTION bool drawImage(const BaseWindow* window, const BaseLoadableHolder& holder, int x, int y, uint16_t index, uint16_t width = 0, uint16_t height = 0);

			/// @brief Draw image from holder
			/// @param window 
			/// @param holder 
			/// @param x 
			/// @param y 
			/// @param pathToImage 
			/// @param width Zero means take entire image width
			/// @param height Zero means take entire image height
			/// @return 
			/// @exception std::out_of_range Wrong pathToImage
			GUI_FRAMEWORK_API_FUNCTION bool drawImage(const BaseWindow* window, const BaseLoadableHolder& holder, int x, int y, const std::filesystem::path& pathToImage, uint16_t width = 0, uint16_t height = 0);
		}
	}
}
