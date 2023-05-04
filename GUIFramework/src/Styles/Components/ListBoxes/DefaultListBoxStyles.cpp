#include "DefaultListBoxStyles.h"

using namespace std;

namespace gui_framework
{
	namespace styles
	{
		DefaultListBoxStyles::DefaultListBoxStyles(bool isSorting)
		{
			if (isSorting)
			{
				this->appendStyle(LBS_SORT);
			}
		}
	}
}
