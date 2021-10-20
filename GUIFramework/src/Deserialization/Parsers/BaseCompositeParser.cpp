#include "BaseCompositeParser.h"

using namespace std;

namespace gui_framework
{
	namespace parsers
	{
		void BaseCompositeParser::parse(const json::utility::objectSmartPointer<json::utility::jsonObject>& description)
		{
			using json::utility::objectSmartPointer;
			using json::utility::jsonObject;

			BaseComponentParser::parse(description);

			windowFunctionName = description->getString("windowFunctionName");

			if (ranges::find_if(description->data, [](const auto& value) { return value.first == "pathToLargeIcon"; }) != description->data.end())
			{
				pathToLargeIcon = description->getString("pathToLargeIcon");
			}

			if (ranges::find_if(description->data, [](const auto& value) { return value.first == "pathToSmallIcon"; }) != description->data.end())
			{
				pathToSmallIcon = description->getString("pathToSmallIcon");
			}

			mode = static_cast<gui_framework::BaseComposite::exitMode>(description->getInt("exitMode"));
		}
	}
}
