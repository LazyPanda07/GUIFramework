#include "Core.h"
#include "IconListViewStyles.h"

using namespace std;

namespace gui_framework
{
	namespace styles
	{
		IconListViewStyles::IconListViewStyles(utility::iconListViewType type)
		{
			this->appendStyle(static_cast<LONG_PTR>(type));
		}
	}
}
