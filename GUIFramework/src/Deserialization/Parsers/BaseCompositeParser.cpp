#include "BaseCompositeParser.h"

#include "BaseComposites/BaseComposite.h"

using namespace std;

namespace gui_framework
{
	namespace parsers
	{
		BaseCompositeParser::BaseCompositeParser() :
			mode(BaseComposite::exitMode::destroyWindow)
		{

		}

		void BaseCompositeParser::parse(const json::utility::jsonObject& description)
		{
			using json::utility::jsonObject;

			BaseComponentParser::parse(description);

			windowFunctionName = description.getString("windowFunctionName");

			if (description.contains("onDestroyFunctionName", json::utility::variantTypeEnum::jString))
			{
				onDestroyFunctionName = description.getString("onDestroyFunctionName");
				onDestroyFunctionModuleName = description.getString("onDestroyFunctionModuleName");
			}

			mode = static_cast<gui_framework::BaseComposite::exitMode>(description.getInt("exitMode"));
		}
	}
}
