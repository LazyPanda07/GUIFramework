#pragma once

#include "BaseCompositeParser.h"

namespace gui_framework
{
	namespace parsers
	{
		struct GUI_FRAMEWORK_API SeparateWindowParser : public BaseCompositeParser
		{
			std::string onCloseFunctionName;
			std::string onCloseFunctionModuleName;

		public:
			SeparateWindowParser() = default;

			void parse(const json::utility::objectSmartPointer<json::utility::jsonObject>& description) override;

			~SeparateWindowParser() = default;
		};
	}
}
