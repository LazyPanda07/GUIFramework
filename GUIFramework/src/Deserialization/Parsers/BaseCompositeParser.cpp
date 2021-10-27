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

			if (description->contains("onDestroyFunctionName", json::utility::variantTypeEnum::jString))
			{
				onDestroyFunctionName = description->getString("onDestroyFunctionName");
				onDestroyFunctionModuleName = description->getString("onDestroyFunctionModuleName");
			}

			mode = static_cast<gui_framework::BaseComposite::exitMode>(description->getInt("exitMode"));
		}
	}
}
