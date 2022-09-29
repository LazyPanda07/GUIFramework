#include "core.h"
#include "HorizontalTrackbarControlStyles.h"

using namespace std;

namespace gui_framework
{
	namespace styles
	{
		HorizontalTrackbarControlStyles::HorizontalTrackbarControlStyles(HorizontalTrackbarControl::horizontalTickPosition position)
		{
			this->appendStyle(TBS_HORZ);

			this->appendStyle(position == HorizontalTrackbarControl::horizontalTickPosition::bottom ? TBS_BOTTOM : (position == HorizontalTrackbarControl::horizontalTickPosition::top ? TBS_TOP : TBS_BOTH));
		}
	}
}
