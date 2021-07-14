#include "pch.h"
#include "ListViewStyles.h"

using namespace std;

namespace gui_framework
{
	namespace styles
	{
		ListViewStyles::ListViewStyles(const ListViewStyles& buttonStyles)
		{
			this->appendStyle(buttonStyles.getStyles());

			this->appendExtendedStyle(buttonStyles.getExtendedStyles());
		}
	}
}
