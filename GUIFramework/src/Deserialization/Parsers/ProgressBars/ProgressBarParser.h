#pragma once

#include "Deserialization/Parsers/BaseComponentParser.h"

namespace gui_framework
{
	namespace parsers
	{
		struct GUI_FRAMEWORK_API ProgressBarParser : public BaseComponentParser
		{
			int minRange;
			int maxRange;
			int updateStep;

		public:
			ProgressBarParser() = default;

			void parse(const json::utility::objectSmartPointer<json::utility::jsonObject>& description) override;

			~ProgressBarParser() = default;
		};
	}
}
