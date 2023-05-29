#include "ImageButtonParser.h"

using namespace std;

namespace gui_framework
{
	namespace parsers
	{
		ImageButtonParser::ImageButtonParser() :
			imageResource(NULL),
			imageWidth(0),
			imageHeight(0),
			dType(ImageButton::drawingType::image),
			iType(ImageButton::imageType::bitmap)
		{

		}

		void ImageButtonParser::parse(const json::utility::jsonObject& description)
		{
			ButtonParser::parse(description);

			pathToImage = description.getString("pathToImage");

			resourceModuleName = description.getString("resourceModuleName");
			imageResource = static_cast<uint32_t>(description.getUnsignedInt("imageResource"));

			dType = static_cast<ImageButton::drawingType>(description.getUnsignedInt("drawingType"));
			iType = static_cast<ImageButton::imageType>(description.getUnsignedInt("drawingType"));

			imageWidth = static_cast<uint16_t>(description.getUnsignedInt("imageWidth"));
			imageHeight = static_cast<uint16_t>(description.getUnsignedInt("imageHeight"));
		}
	}
}
