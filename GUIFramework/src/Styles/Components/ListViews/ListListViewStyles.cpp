#include "Core.h"
#include "ListListViewStyles.h"

using namespace std;

namespace gui_framework
{
	namespace styles
	{
		ListListViewStyles::ListListViewStyles()
		{
			this->appendStyle(LVS_LIST);
		}

		ListListViewStyles::ListListViewStyles(const ListListViewStyles& listViewStyles) :
			ListListViewStyles()
		{
			this->appendStyle(listViewStyles.getStyles());

			this->appendExtendedStyle(listViewStyles.getExtendedStyles());
		}
	}
}
