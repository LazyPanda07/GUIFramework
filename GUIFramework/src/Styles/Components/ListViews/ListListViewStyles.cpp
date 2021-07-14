#include "pch.h"
#include "ListListViewStyles.h"

using namespace std;

namespace gui_framework
{
	namespace styles
	{
		ListListViewStyles::ListListViewStyles(const ListListViewStyles& buttonStyles)
		{
			this->appendStyle(LVS_LIST);

			this->appendStyle(buttonStyles.getStyles());

			this->appendExtendedStyle(buttonStyles.getExtendedStyles());
		}
	}
}
