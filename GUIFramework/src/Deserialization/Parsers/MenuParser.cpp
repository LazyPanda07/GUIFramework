#include "MenuParser.h"

#include "Utility/Utility.h"
#include "Interfaces/Utility/ISerializable.h"

using namespace std;

namespace gui_framework
{
	namespace parsers
	{
		void MenuParser::parse(json::utility::jsonObject& description)
		{
			using json::utility::jsonObject;

			uint32_t codepage = interfaces::ISerializable::getCodepage();

			mainMenuName = utility::to_wstring(description.getString("mainMenuName"), codepage);

			mainMenuItems = move(const_cast<vector<jsonObject>&>(description.getArray("mainMenuItems")));

			popupItems = move(const_cast<vector<jsonObject>&>(description.getArray("popupItems")));
		}
	}
}
