#pragma once

#include "BaseCompositeParser.h"

namespace gui_framework
{
	namespace parsers
	{
		struct GUI_FRAMEWORK_API GroupBoxParser : public BaseCompositeParser
		{
			std::vector<GroupBox::radioButtonData> data;

		public:
			GroupBoxParser() = default;

			void parse(const json::utility::objectSmartPointer<json::utility::jsonObject>&description) override;

			~GroupBoxParser() = default;
		};
	}
}
