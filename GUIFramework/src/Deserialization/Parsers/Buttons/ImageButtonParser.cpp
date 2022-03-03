#include "ImageButtonParser.h"

using namespace std;

namespace gui_framework
{
	namespace parsers
	{
		void ImageButtonParser::parse(const json::utility::jsonObject& description)
		{
			ButtonParser::parse(description);

			imageWidth = static_cast<uint16_t>(description.getUnsignedInt("imageWidth"));
			imageHeight = static_cast<uint16_t>(description.getUnsignedInt("imageHeight"));

			pathToImage = description.getString("pathToImage");

			type = static_cast<ImageButton::drawingType>(description.getUnsignedInt("drawingType"));
		}
	}
}
