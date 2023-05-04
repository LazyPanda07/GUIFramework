#pragma once

#include "Deserialization/Parsers/BaseComponentParser.h"
#include "Utility/Holders/LoadableHolders/BaseLoadableHolder.h"

namespace gui_framework
{
	namespace parsers
	{
		/// @brief Parse IconListView and ListIconListView specific properties
		struct GUI_FRAMEWORK_API IconListViewParser : virtual public BaseComponentParser
		{
			std::vector<std::filesystem::path> icons;
			uint16_t imagesWidth;
			uint16_t imagesHeight;
			utility::iconListViewType type;

		public:
			IconListViewParser();

			virtual void parse(const json::utility::jsonObject& description) override;

			~IconListViewParser() = default;
		};
	}
}
