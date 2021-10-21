#include "headers.h"
#include "MultipleSelectListBoxStyles.h"

using namespace std;

namespace gui_framework
{
	namespace styles
	{
		MultipleSelectListBoxStyles::MultipleSelectListBoxStyles(bool isSorting)
		{
			this->appendStyle(LBS_MULTIPLESEL);

			if (isSorting)
			{
				this->appendStyle(LBS_SORT);
			}
		}
	}
}
