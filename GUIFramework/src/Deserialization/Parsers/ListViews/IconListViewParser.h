#pragma once

#include "headers.h"
#include "Deserialization/Parsers/BaseComponentParser.h"

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
			IconListViewParser() = default;

			virtual void parse(const json::utility::objectSmartPointer<json::utility::jsonObject>& description) override;

			~IconListViewParser() = default;
		};
	}
}
