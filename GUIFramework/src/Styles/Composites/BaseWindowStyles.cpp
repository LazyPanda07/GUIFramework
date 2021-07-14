#include "pch.h"
#include "BaseWindowStyles.h"

using namespace std;

namespace gui_framework
{
	namespace styles
	{
		BaseWindowStyles::BaseWindowStyles(bool maximize, bool minimize)
		{
			if (maximize)
			{
				this->appendStyle(WS_MAXIMIZE);
			}

			if (minimize)
			{
				this->appendStyle(WS_MINIMIZE);
			}
		}
	}
}
