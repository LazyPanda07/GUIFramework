#include "ComboBoxParser.h"

#include "Utility/Utility.h"
#include "Interfaces/Utility/ISerializable.h"

using namespace std;

namespace gui_framework
{
	namespace parsers
	{
		void ComboBoxParser::parse(const json::utility::jsonObject& description)
		{
			BaseComponentParser::parse(description);

			vector<string> tem = json::utility::JSONArrayWrapper(description.getArray("comboBoxValues")).getAsStringArray();
			uint32_t codepage = interfaces::ISerializable::getCodepage();

			values.reserve(tem.size());

			for (const auto& i : tem)
			{
				values.emplace_back(utility::to_wstring(i, codepage));
			}

			functionName = description.getString("functionName");
			moduleName = description.getString("moduleName");
		}
	}
}
