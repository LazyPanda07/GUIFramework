#pragma once

#include "Utility/Holders/LoadableHolders/BaseLoadableHolder.h"
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
			/// @return 
			/// @exception std::out_of_range Wrong index
			GUI_FRAMEWORK_API_FUNCTION bool drawImageByIndex(const BaseWindow* window, const BaseLoadableHolder& holder, int x, int y, uint16_t index);

			/// @brief Draw image from holder
			/// @param window 
			/// @param holder 
			/// @param x 
			/// @param y 
			/// @param pathToImage 
			/// @return 
			/// @exception std::out_of_range Wrong pathToImage
			GUI_FRAMEWORK_API_FUNCTION bool drawImageByPath(const BaseWindow* window, const BaseLoadableHolder& holder, int x, int y, const std::filesystem::path& pathToImage);
		}
	}
}
