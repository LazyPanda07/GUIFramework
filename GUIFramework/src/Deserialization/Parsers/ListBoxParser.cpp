#include "ListBoxParser.h"

#include "Utility/Utility.h"
#include "Interfaces/Utility/ISerializable.h"

using namespace std;

namespace gui_framework
{
	namespace parsers
	{
		void ListBoxParser::parse(const json::utility::objectSmartPointer<json::utility::jsonObject>& description)
		{
			BaseComponentParser::parse(description);

			vector<string> tem = json::utility::JSONArrayWrapper(description->getArray("listBoxValues")).getAsStringArray();
			uint32_t codepage = interfaces::ISerializable::getCodepage();

			values.reserve(tem.size());

			for (const auto& i : tem)
			{
				values.emplace_back(utility::to_wstring(i, codepage));
			}

			columnWidth = static_cast<uint8_t>(description->getInt("columnWidth"));
		}
	}
}
