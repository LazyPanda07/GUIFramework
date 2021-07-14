#include "pch.h"
#include "DefaultRichEditStyles.h"

using namespace std;

namespace gui_framework
{
	namespace styles
	{
		DefaultRichEditStyles::DefaultRichEditStyles()
		{
			this->appendStyle(WS_VSCROLL);

			this->appendStyle(WS_HSCROLL);
		}
	}
}
