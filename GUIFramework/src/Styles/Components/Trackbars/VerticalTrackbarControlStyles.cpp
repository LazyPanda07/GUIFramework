#include "headers.h"
#include "VerticalTrackbarControlStyles.h"

using namespace std;

namespace gui_framework
{
	namespace styles
	{
		VerticalTrackbarControlStyles::VerticalTrackbarControlStyles(VerticalTrackbarControl::verticalTickPosition position)
		{
			this->appendStyle(TBS_VERT);

			this->appendStyle(position == VerticalTrackbarControl::verticalTickPosition::left ? TBS_LEFT : (position == VerticalTrackbarControl::verticalTickPosition::right ? TBS_RIGHT : TBS_BOTH));
		}
	}
}
