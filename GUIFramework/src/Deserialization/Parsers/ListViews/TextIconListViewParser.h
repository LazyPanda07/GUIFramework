#pragma once

#include "IconListViewParser.h"
#include "TextListViewParser.h"

namespace gui_framework
{
	namespace parsers
	{
		struct GUI_FRAMEWORK_API TextIconListViewParser :
			public IconListViewParser,
			public TextListViewParser
		{
		public:
			TextIconListViewParser() = default;

			void parse(const json::utility::objectSmartPointer<json::utility::jsonObject>& description) override;

			~TextIconListViewParser() = default;
		};
	}
}
