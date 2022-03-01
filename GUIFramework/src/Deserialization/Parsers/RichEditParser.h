#pragma once

#include "headers.h"
#include "BaseComponentParser.h"
#include "BaseComponents/StandardComponents/BaseRichEdit.h"

namespace gui_framework
{
	namespace parsers
	{
		/// @brief Parse RichEdit specific properties
		struct GUI_FRAMEWORK_API RichEditParser : public BaseComponentParser
		{
			std::array<std::pair<std::string, std::string>, BaseRichEdit::urlDetectEventSize> callbacks;
			bool isMultiLine;
			uint64_t limitTextCount;

		public:
			RichEditParser();

			void parse(const json::utility::jsonObject& description) override;

			~RichEditParser() = default;
		};
	}
}
