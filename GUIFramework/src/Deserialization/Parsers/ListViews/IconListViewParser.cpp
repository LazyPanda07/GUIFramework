#include "IconListViewParser.h"

using namespace std;

namespace gui_framework
{
	namespace parsers
	{
		void IconListViewParser::parse(const json::utility::objectSmartPointer<json::utility::jsonObject>& description)
		{
			BaseComponentParser::parse(description);

			icons = json::utility::JSONArrayWrapper(description->getArray("listViewIconValues")).getAsStringArray();

			imagesWidth = static_cast<uint16_t>(description->getUnsignedInt("imagesWidth"));
			imagesHeight= static_cast<uint16_t>(description->getUnsignedInt("imagesHeight"));
		}
	}
}
