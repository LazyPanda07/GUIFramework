#pragma once

#include "BaseComponentParser.h"

namespace gui_framework
{
	namespace parsers
	{
		/// @brief Parse TrackbarControl specific properties
		struct GUI_FRAMEWORK_API TrackbarControlParser : public BaseComponentParser
		{
			int minRange;
			int maxRange;
			int selectionStart;
			int selectionEnd;

		public:
			TrackbarControlParser() = default;

			void parse(const json::utility::jsonObject& description) override;

			~TrackbarControlParser() = default;
		};
	}
}
