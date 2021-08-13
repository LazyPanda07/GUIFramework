#pragma once

#include "pch.h"
#include "Utility/Holders/LoadableHolders/ImagesHolder.h"
#include "Utility/Holders/LoadableHolders/IconsHolder.h"
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
			GUI_FRAMEWORK_API_FUNCTION bool drawImageByIndex(const BaseWindow* window, const ImagesHolder& holder, int x, int y, uint16_t index);

			/// @brief Draw image from holder
			/// @param window 
			/// @param holder 
			/// @param x 
			/// @param y 
			/// @param pathToImage 
			/// @return 
			/// @exception std::out_of_range Wrong pathToImage
			GUI_FRAMEWORK_API_FUNCTION bool drawImageByPath(const BaseWindow* window, const ImagesHolder& holder, int x, int y, const std::filesystem::path& pathToImage);

			/// @brief Draw icon from holder
			/// @param window 
			/// @param holder 
			/// @param x 
			/// @param y 
			/// @param index Internal index of image
			/// @return 
			/// @exception std::out_of_range Wrong index
			GUI_FRAMEWORK_API_FUNCTION bool drawIconByIndex(const BaseWindow* window, const IconsHolder& holder, int x, int y, uint16_t index);

			/// @brief Draw icon from holder
			/// @param window 
			/// @param holder 
			/// @param x 
			/// @param y 
			/// @param pathToImage 
			/// @return 
			/// @exception std::out_of_range Wrong pathToImage
			GUI_FRAMEWORK_API_FUNCTION bool drawIconByPath(const BaseWindow* window, const IconsHolder& holder, int x, int y, const std::filesystem::path& pathToIcon);
		}
	}
}
