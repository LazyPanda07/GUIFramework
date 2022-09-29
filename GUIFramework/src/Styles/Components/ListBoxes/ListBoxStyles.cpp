#include "core.h"
#include "ListBoxStyles.h"

using namespace std;

namespace gui_framework
{
	namespace styles
	{
		ListBoxStyles::ListBoxStyles(const ListBoxStyles& listBoxStyles)
		{
			this->appendStyle(listBoxStyles.getStyles());

			this->appendExtendedStyle(listBoxStyles.getExtendedStyles());
		}
	}
}
