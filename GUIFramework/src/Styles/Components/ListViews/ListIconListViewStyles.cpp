#include "core.h"
#include "ListIconListViewStyles.h"

using namespace std;

namespace gui_framework
{
	namespace styles
	{
		ListIconListViewStyles::ListIconListViewStyles(utility::iconListViewType type)
		{
			this->appendStyle(static_cast<LONG_PTR>(type));
		}
	}
}
