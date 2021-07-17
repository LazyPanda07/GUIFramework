#include "pch.h"
#include "ComboBoxStyles.h"

using namespace std;

namespace gui_framework
{
	namespace styles
	{
		ComboBoxStyles::ComboBoxStyles(const ComboBoxStyles& comboBoxStyles)
		{
			this->appendStyle(comboBoxStyles.getStyles());

			this->appendExtendedStyle(comboBoxStyles.getExtendedStyles());
		}
	}
}
