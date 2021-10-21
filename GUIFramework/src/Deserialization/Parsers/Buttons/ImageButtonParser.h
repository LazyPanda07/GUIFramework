#pragma once

#include "ButtonParser.h"

namespace gui_framework
{
	namespace parsers
	{
		/// @brief Parse ImageButton specific properties
		struct GUI_FRAMEWORK_API ImageButtonParser : public ButtonParser
		{
			uint16_t imageWidth;
			uint16_t imageHeight;
			std::string pathToImage;
			ImageButton::drawingType type;

		public:
			ImageButtonParser() = default;

			void parse(const json::utility::objectSmartPointer<json::utility::jsonObject>& description) override;

			~ImageButtonParser() = default;
		};
	}
}
