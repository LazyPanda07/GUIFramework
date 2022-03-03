#pragma once

#include "IconListViewParser.h"
#include "TextListViewParser.h"

namespace gui_framework
{
	namespace parsers
	{
		/// @brief Parse TextIconListView and ListTextIconListView specific properties
		struct GUI_FRAMEWORK_API TextIconListViewParser :
			public IconListViewParser,
			public TextListViewParser
		{
		public:
			TextIconListViewParser() = default;

			void parse(const json::utility::jsonObject& description) override;

			~TextIconListViewParser() = default;
		};
	}
}
