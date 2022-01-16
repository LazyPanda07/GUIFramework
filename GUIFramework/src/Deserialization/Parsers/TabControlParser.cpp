#include "TabControlParser.h"

#include "Utility/Utility.h"
#include "Interfaces/Utility/ISerializable.h"

using namespace std;

namespace gui_framework
{
	namespace parsers
	{
		void TabControlParser::parse(const json::utility::jsonObject& description)
		{
			BaseComponentParser::parse(description);

			imagesWidth = static_cast<uint16_t>(description.getUnsignedInt("imagesWidth"));
			imagesHeight = static_cast<uint16_t>(description.getUnsignedInt("imagesHeight"));

			const auto& jsonTabs = description.getArray("tabs");

			tabs.reserve(jsonTabs.size());

			for (const auto& i : jsonTabs)
			{
				auto& tab = tabs.emplace_back();

				if (i.contains("tabText", json::utility::variantTypeEnum::jString))
				{
					tab.text = utility::to_wstring(i.getString("tabText"), interfaces::ISerializable::getCodepage());
				}

				if (i.contains("tabImagePath", json::utility::variantTypeEnum::jString))
				{
					tab.pathToImage = i.getString("tabImagePath");
				}

				if (i.contains("functionName", json::utility::variantTypeEnum::jString))
				{
					tab.functionName = i.getString("functionName");
					tab.moduleName = i.getString("moduleName");
				}
			}
		}
	}
}
