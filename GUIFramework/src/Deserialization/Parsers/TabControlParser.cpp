#include "TabControlParser.h"

using namespace std;

namespace gui_framework
{
	namespace parsers
	{
		void TabControlParser::parse(const json::utility::objectSmartPointer<json::utility::jsonObject>& description)
		{
			BaseComponentParser::parse(description);

			imagesWidth = static_cast<uint16_t>(description->getUnsignedInt("imagesWidth"));
			imagesHeight = static_cast<uint16_t>(description->getUnsignedInt("imagesHeight"));

			const auto& jsonTabs = description->getArray("tabs");

			tabs.reserve(jsonTabs.size());

			for (const auto& i : jsonTabs)
			{
				tabs.emplace_back();

				if (i->contains("tabText", json::utility::variantTypeEnum::jString))
				{
					tabs.back().text = utility::to_wstring(i->getString("tabText"), interfaces::ISerializable::getCodepage());
				}

				if (i->contains("tabImagePath", json::utility::variantTypeEnum::jString))
				{
					tabs.back().pathToImage = i->getString("tabImagePath");
				}

				if (i->contains("functionName", json::utility::variantTypeEnum::jString))
				{
					tabs.back().functionName = i->getString("functionName");
					tabs.back().moduleName = i->getString("moduleName");
				}
			}
		}
	}
}
