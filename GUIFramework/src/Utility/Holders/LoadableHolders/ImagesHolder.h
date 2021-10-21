#pragma once

#include "headers.h"
#include "BaseLoadableHolder.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief Images loader
		class GUI_FRAMEWORK_API ImagesHolder final : public BaseLoadableHolder
		{
		public:
			ImagesHolder(uint16_t imagesWidth, uint16_t imagesHeight, size_t count = standard_sizes::defaultImagesCount);

			/// @brief 
			/// @param pathToIcon 
			/// @return
			/// @exception std::out_of_range  
			HBITMAP getImage(const std::filesystem::path& pathToImage) const;

			/// @brief 
			/// @param iconIndex 
			/// @return
			/// @exception std::out_of_range  
			HBITMAP getImage(uint16_t imageIndex) const;

			/// @brief 
			/// @param pathToImage 
			/// @return Index of newly added image
			uint16_t addImage(const std::filesystem::path& pathToImage) override;

			~ImagesHolder() = default;
		};
	}
}
