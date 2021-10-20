#pragma once

#include "BaseComponentParser.h"

namespace gui_framework
{
	namespace parsers
	{
		struct GUI_FRAMEWORK_API ComboBoxParser : public BaseComponentParser
		{
			std::vector<std::wstring> values;
			std::string functionName;
			std::string moduleName;

		public:
			ComboBoxParser() = default;

			void parse(const json::utility::objectSmartPointer<json::utility::jsonObject>& description) override;

			~ComboBoxParser() = default;
		};
	}
}
