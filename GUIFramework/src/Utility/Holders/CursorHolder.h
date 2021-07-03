#pragma once

#include "BaseLoadableHolder.h"

namespace gui_framework
{
	namespace utility
	{
		class GUI_FRAMEWORK_API CursorHolder final : public BaseLoadableHolder
		{
		public:
			CursorHolder(uint16_t imagesWidth, uint16_t imagesHeight, size_t count = standard_sizes::defaultImagesCount);

			uint16_t addImage(const std::filesystem::path& pathToImage) override;

			~CursorHolder() = default;
		};
	}
}
