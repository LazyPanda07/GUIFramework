#pragma once

#include "BaseCompositeParser.h"
#include "Composites/GroupBox.h"

namespace gui_framework
{
	namespace parsers
	{
		/// @brief Parse GroupBox specific properties
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
