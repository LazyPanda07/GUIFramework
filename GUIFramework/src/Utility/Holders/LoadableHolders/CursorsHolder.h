#pragma once

#include "BaseLoadableHolder.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief Cursors loader
		class GUI_FRAMEWORK_API CursorsHolder final : public BaseLoadableHolder
		{
		public:
			CursorsHolder(uint16_t imagesWidth, uint16_t imagesHeight, size_t count = standard_sizes::defaultImagesCount);

			/// @brief 
			/// @param pathToCursor
			/// @return Index of newly added cursor
			uint16_t addImage(const std::filesystem::path& pathToCursor) override;

			~CursorsHolder() = default;
		};
	}
}
