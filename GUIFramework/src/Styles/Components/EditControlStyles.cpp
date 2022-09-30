#include "Core.h"
#include "EditControlStyles.h"

using namespace std;

namespace gui_framework
{
	namespace styles
	{
		EditControlStyles::EditControlStyles(bool isMultiLine)
		{
			if (isMultiLine)
			{
				this->appendStyle(ES_MULTILINE);
			}
		}
	}
}
