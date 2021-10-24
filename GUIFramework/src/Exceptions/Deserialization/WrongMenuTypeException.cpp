#include "WrongMenuTypeException.h"

using namespace std;

namespace gui_framework
{
	namespace exceptions
	{
		namespace deserialization
		{
			WrongMenuTypeException::WrongMenuTypeException(const string& type) :
				BaseDeserializationException
				(
					format(R"(Undefined menu type "{}". Only available types: "{}", "{}")", type, standard_menu_items::menuItem, standard_menu_items::dropDownMenuItem)
				)
			{

			}
		}
	}
}
