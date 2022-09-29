#pragma once

#include "core.h"
#include "BaseLoadableHolder.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief Icons loader
		class GUI_FRAMEWORK_API IconsHolder final : public BaseLoadableHolder
		{
		public:
			IconsHolder(uint16_t imagesWidth, uint16_t imagesHeight, size_t count = standard_sizes::defaultImagesCount);

			/// @brief 
			/// @param pathToIcon 
			/// @return
			/// @exception std::out_of_range  
			HICON getIcon(const std::filesystem::path& pathToIcon) const;

			/// @brief 
			/// @param iconIndex 
			/// @return
			/// @exception std::out_of_range  
			HICON getIcon(uint16_t iconIndex) const;

			/// @brief 
			/// @param pathToIcon
			/// @return Index of newly added icon
			uint16_t addImage(const std::filesystem::path& pathToIcon) override;

			~IconsHolder() = default;
		};
	}
}
