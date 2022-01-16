#include "IconListViewParser.h"

#include "Utility/Holders/LoadableHolders/BaseLoadableHolder.h"

using namespace std;

namespace gui_framework
{
	namespace parsers
	{
		IconListViewParser::IconListViewParser() :
			imagesWidth(0),
			imagesHeight(0),
			type(utility::iconListViewType::icon)
		{

		}

		void IconListViewParser::parse(const json::utility::jsonObject& description)
		{
			BaseComponentParser::parse(description);

			vector<string> tem = json::utility::JSONArrayWrapper(description.getArray("listViewIconValues")).getAsStringArray();

			icons.reserve(tem.size());

			for (const auto& i : tem)
			{
				icons.emplace_back(i);
			}

			imagesWidth = static_cast<uint16_t>(description.getUnsignedInt("imagesWidth"));
			imagesHeight= static_cast<uint16_t>(description.getUnsignedInt("imagesHeight"));

			if (imagesWidth == standard_sizes::largeIconWidth && imagesHeight == standard_sizes::largeIconHeight)
			{
				type = utility::iconListViewType::icon;
			}
			else
			{
				type = utility::iconListViewType::smallIcon;
			}
		}
	}
}
