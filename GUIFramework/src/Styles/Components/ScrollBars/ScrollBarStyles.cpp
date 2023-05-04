#include "ScrollBarStyles.h"

using namespace std;

namespace gui_framework
{
	namespace styles
	{
		ScrollBarStyles::ScrollBarStyles(const ScrollBarStyles& scrollBarStyles)
		{
			this->appendStyle(scrollBarStyles.getStyles());

			this->appendExtendedStyle(scrollBarStyles.getExtendedStyles());
		}
	}
}
