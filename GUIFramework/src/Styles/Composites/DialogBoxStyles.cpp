#include "pch.h"
#include "DialogBoxStyles.h"

using namespace std;

namespace gui_framework
{
	namespace styles
	{
		DialogBoxStyles::DialogBoxStyles()
		{
			this->appendStyle(WS_SYSMENU);

			this->appendStyle(WS_CAPTION);

			this->appendExtendedStyle(WS_EX_DLGMODALFRAME);
		}
	}
}
