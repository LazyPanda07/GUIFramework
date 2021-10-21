#pragma once

#include "Deserialization/Parsers/BaseComponentParser.h"

namespace gui_framework
{
	namespace parsers
	{
		struct GUI_FRAMEWORK_API TextListViewParser : virtual public BaseComponentParser
		{
			std::vector<std::wstring> values;

		public:
			TextListViewParser() = default;

			virtual void parse(const json::utility::objectSmartPointer<json::utility::jsonObject>& description) override;

			~TextListViewParser() = default;
		};
	}
}
