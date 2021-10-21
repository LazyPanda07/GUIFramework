#include "headers.h"
#include "ListViewStyles.h"

using namespace std;

namespace gui_framework
{
	namespace styles
	{
		ListViewStyles::ListViewStyles(const ListViewStyles& listViewStyles)
		{
			this->appendStyle(listViewStyles.getStyles());

			this->appendExtendedStyle(listViewStyles.getExtendedStyles());
		}
	}
}
