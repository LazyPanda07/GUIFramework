#include "TextIconListViewParser.h"

using namespace std;

namespace gui_framework
{
	namespace parsers
	{
		void TextIconListViewParser::parse(const json::utility::jsonObject& description)
		{
			IconListViewParser::parse(description);

			TextListViewParser::parse(description);
		}
	}
}
