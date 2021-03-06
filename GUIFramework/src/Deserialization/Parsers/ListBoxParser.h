#pragma once

#include "BaseComponentParser.h"

namespace gui_framework
{
	namespace parsers
	{
		/// @brief Parse ListBox and MultipleSelectListBox specific properties
		struct GUI_FRAMEWORK_API ListBoxParser : public BaseComponentParser
		{
			std::vector<std::wstring> values;
			uint8_t columnWidth;

		public:
			ListBoxParser() = default;

			void parse(const json::utility::jsonObject& description) override;

			~ListBoxParser() = default;
		};
	}
}
