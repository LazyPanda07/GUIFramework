#include "ButtonParser.h"

#include "Utility/Utility.h"
#include "Interfaces/Utility/ISerializable.h"

using namespace std;

namespace gui_framework
{
	namespace parsers
	{
		void ButtonParser::parse(const json::utility::jsonObject& description)
		{
			BaseComponentParser::parse(description);

			uint32_t codepage = interfaces::ISerializable::getCodepage();
			
			text = utility::to_wstring(description.getString("text"), codepage);

			onClickFunctionName = description.getString("functionName");

			onClickFunctionModule = description.getString("moduleName");

			pathToModule = description.getString("pathToModule");
		}
	}
}
