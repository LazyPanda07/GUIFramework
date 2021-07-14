#include "pch.h"
#include "SeparateWindowStyles.h"

using namespace std;

namespace gui_framework
{
	namespace styles
	{
		SeparateWindowStyles::SeparateWindowStyles(bool maximize, bool minimize)
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
