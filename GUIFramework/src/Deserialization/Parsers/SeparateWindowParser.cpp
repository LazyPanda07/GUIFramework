#include "SeparateWindowParser.h"

using namespace std;

namespace gui_framework
{
	namespace parsers
	{
		void SeparateWindowParser::parse(const json::utility::jsonObject& description)
		{
			BaseComponentParser::parse(description);

			if (description.contains("pathToLargeIcon", json::utility::variantTypeEnum::jString))
			{
				pathToLargeIcon = description.getString("pathToLargeIcon");
			}

			if (description.contains("pathToSmallIcon", json::utility::variantTypeEnum::jString))
			{
				pathToSmallIcon = description.getString("pathToSmallIcon");
			}

			if (description.contains("onCloseFunctionName", json::utility::variantTypeEnum::jString))
			{
				onCloseFunctionName = description.getString("onCloseFunctionName");
				onCloseFunctionModuleName = description.getString("onCloseFunctionModuleName");
			}
		}
	}
}
