#include "CheckBoxParser.h"

using namespace std;

namespace gui_framework
{
	namespace parsers
	{
		void CheckBoxParser::parse(const json::utility::objectSmartPointer<json::utility::jsonObject>& description)
		{
			ButtonParser::parse(description);

			try
			{
				onCheckFunctionName = description->getString("checkFunctionName");
				onCheckModuleName = description->getString("checkModuleName");
			}
			catch (const json::exceptions::CantFindValueException&)
			{

			}

			try
			{
				onClearFunctionName = description->getString("clearFunctionName");
				onClearModuleName = description->getString("clearModuleName");
			}
			catch (const json::exceptions::CantFindValueException&)
			{

			}
		}
	}
}
