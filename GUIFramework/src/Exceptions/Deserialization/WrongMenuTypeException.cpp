#include "WrongMenuTypeException.h"

using namespace std;

namespace gui_framework
{
	namespace exceptions
	{
		namespace deserialization
		{
			WrongMenuTypeException::WrongMenuTypeException(const string& type, string_view fileName, string_view methodName, int line) :
				BaseDeserializationException
				(
					format(R"(Undefined menu type "{}". Only available types: "{}", "{}")"sv, type, standard_menu_items::menuItem, standard_menu_items::dropDownMenuItem),
					fileName,
					methodName,
					line
				)
			{

			}
		}
	}
}
