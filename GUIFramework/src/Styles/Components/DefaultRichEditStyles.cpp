#include "core.h"
#include "DefaultRichEditStyles.h"

using namespace std;

namespace gui_framework
{
	namespace styles
	{
		DefaultRichEditStyles::DefaultRichEditStyles(bool isMultiLine)
		{
			if (isMultiLine)
			{
				this->appendStyle(ES_MULTILINE);
			}

			this->appendStyle(WS_VSCROLL);

			this->appendStyle(WS_HSCROLL);
		}
	}
}
