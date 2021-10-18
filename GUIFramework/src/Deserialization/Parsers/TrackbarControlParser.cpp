#include "TrackbarControlParser.h"

using namespace std;

namespace gui_framework
{
	namespace parsers
	{
		void TrackbarControlParser::parse(const json::utility::objectSmartPointer<json::utility::jsonObject>& description)
		{
			BaseComponentParser::parse(description);

			minRange = static_cast<int>(description->getInt("minRange"));
			maxRange = static_cast<int>(description->getInt("maxRange"));
			selectionStart = static_cast<int>(description->getInt("selectionStart"));
			selectionEnd = static_cast<int>(description->getInt("selectionEnd"));
		}
	}
}
