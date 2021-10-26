#include "SeparateWindowParser.h"

using namespace std;

namespace gui_framework
{
	namespace parsers
	{
		void SeparateWindowParser::parse(const json::utility::objectSmartPointer<json::utility::jsonObject>& description)
		{
			BaseComponentParser::parse(description);

			if (description->contains("onCloseFunctionName", json::utility::variantTypeEnum::jString))
			{
				onCloseFunctionName = description->getString("onCloseFunctionName");
				onCloseFunctionModuleName = description->getString("onCloseFunctionModuleName");
			}
		}
	}
}
