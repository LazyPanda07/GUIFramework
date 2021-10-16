#pragma once

#include "headers.h"
#include "BaseComponentParser.h"

namespace gui_framework
{
	namespace parsers
	{
		struct GUI_FRAMEWORK_API RichEditParser : public BaseComponentParser
		{
			std::array<std::pair<std::string, std::string>, BaseRichEdit::urlDetectEventSize> callbacks;

		public:
			RichEditParser();

			void parse(const json::utility::objectSmartPointer<json::utility::jsonObject>& description) override;

			~RichEditParser() = default;
		};
	}
}
