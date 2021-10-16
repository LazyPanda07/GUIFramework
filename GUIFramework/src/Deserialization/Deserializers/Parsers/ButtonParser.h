#pragma once

#include "headers.h"
#include "BaseComponentParser.h"

namespace gui_framework
{
	namespace parsers
	{
		struct GUI_FRAMEWORK_API ButtonParser : public BaseComponentParser
		{
			std::wstring text;
			std::string onClickFunctionName;
			std::string onClickFunctionModule;

		public:
			ButtonParser() = default;

			void parse(const json::utility::objectSmartPointer<json::utility::jsonObject>& description) override;

			~ButtonParser() = default;
		};
	}
}
