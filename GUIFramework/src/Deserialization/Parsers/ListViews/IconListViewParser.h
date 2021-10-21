#pragma once

#include "Deserialization/Parsers/BaseComponentParser.h"

namespace gui_framework
{
	namespace parsers
	{
		struct GUI_FRAMEWORK_API IconListViewParser : virtual public BaseComponentParser
		{
			std::vector<std::string> icons;
			uint16_t imagesWidth;
			uint16_t imagesHeight;

		public:
			IconListViewParser() = default;

			virtual void parse(const json::utility::objectSmartPointer<json::utility::jsonObject>& description) override;

			~IconListViewParser() = default;
		};
	}
}
