#pragma once

#include "Deserialization/Parsers/BaseComponentParser.h"

namespace gui_framework
{
	namespace parsers
	{
		/// @brief Parse InfiniteProgressBar specific properties
		struct GUI_FRAMEWORK_API InfiniteProgressBarParser : public BaseComponentParser
		{
			int animationPeriod;

		public:
			InfiniteProgressBarParser() = default;

			void parse(const json::utility::objectSmartPointer<json::utility::jsonObject>& description) override;

			~InfiniteProgressBarParser() = default;
		};
	}
}
