#pragma once

#include "BaseComponentParser.h"

namespace gui_framework
{
	namespace parsers
	{
		/// @brief Parse TabControl specific properties
		struct GUI_FRAMEWORK_API TabControlParser : public BaseComponentParser
		{
			std::vector<BaseTabControl::tabData> tabs;
			uint16_t imagesWidth;
			uint16_t imagesHeight;

		public:
			TabControlParser() = default;

			void parse(const json::utility::objectSmartPointer<json::utility::jsonObject>& description) override;

			~TabControlParser() = default;
		};
	}
}
