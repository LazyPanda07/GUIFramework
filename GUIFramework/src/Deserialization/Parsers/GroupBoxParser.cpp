#include "GroupBoxParser.h"

using namespace std;

namespace gui_framework
{
	namespace parsers
	{
		void GroupBoxParser::parse(const json::utility::objectSmartPointer<json::utility::jsonObject>& description)
		{
			using json::utility::objectSmartPointer;
			using json::utility::jsonObject;

			BaseCompositeParser::parse(description);

			const auto& children = description->getArray("children");
			uint32_t codepage = interfaces::ISerializable::getCodepage();

			data.reserve(children.size());

			for (const auto& i : children)
			{
				const auto& [componentName, tem] = get<objectSmartPointer<jsonObject>>(i->data.front().second)->data.front();

				const auto& child = get<objectSmartPointer<jsonObject>>(tem);

				auto& radioButtonData = data.emplace_back();

				radioButtonData.functionName = child->getString("functionName");

				radioButtonData.moduleName = child->getString("moduleName");

				radioButtonData.radioButtonText = utility::to_wstring(child->getString("text"), codepage);

				radioButtonData.radioButtonName = utility::to_wstring(componentName, codepage);

				radioButtonData.x = static_cast<int>(child->getInt("desiredX"));

				radioButtonData.y = static_cast<int>(child->getInt("desiredY"));

				radioButtonData.width = static_cast<uint16_t>(child->getUnsignedInt("desiredWidth"));

				radioButtonData.height = static_cast<uint16_t>(child->getUnsignedInt("desiredHeight"));
			}
		}
	}
}
