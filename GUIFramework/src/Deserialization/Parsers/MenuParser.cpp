#include "MenuParser.h"

using namespace std;

namespace gui_framework
{
	namespace parsers
	{
		void MenuParser::parse(json::utility::objectSmartPointer<json::utility::jsonObject>& description)
		{
			using json::utility::objectSmartPointer;
			using json::utility::jsonObject;

			uint32_t codepage = interfaces::ISerializable::getCodepage();

			mainMenuName = utility::to_wstring(description->getString("mainMenuName"), codepage);

			mainMenuItems = move(const_cast<vector<objectSmartPointer<jsonObject>>&>(description->getArray("mainMenuItems")));

			popupItems = move(const_cast<vector<objectSmartPointer<jsonObject>>&>(description->getArray("popupItems")));
		}
	}
}
