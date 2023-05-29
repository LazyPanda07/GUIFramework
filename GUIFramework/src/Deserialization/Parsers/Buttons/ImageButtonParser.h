#pragma once

#include "ButtonParser.h"
#include "Components/Buttons/ImageButton.h"

namespace gui_framework
{
	namespace parsers
	{
		/// @brief Parse ImageButton specific properties
		struct GUI_FRAMEWORK_API ImageButtonParser : public ButtonParser
		{
			std::string pathToImage;
			std::string resourceModuleName;
			uint32_t imageResource;
			ImageButton::drawingType dType;
			ImageButton::imageType iType;
			uint16_t imageWidth;
			uint16_t imageHeight;

		public:
			ImageButtonParser();

			void parse(const json::utility::jsonObject& description) override;

			~ImageButtonParser() = default;
		};
	}
}
