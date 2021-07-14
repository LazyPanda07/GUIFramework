#pragma once

#include "Styles/Components/TrackbarControlStyles.h"
#include "Components/Trackbars/VerticalTrackbarControl.h"

namespace gui_framework
{
	namespace styles
	{
		class GUI_FRAMEWORK_API VerticalTrackbarControlStyles : public TrackbarControlStyles
		{
		public:
			VerticalTrackbarControlStyles(VerticalTrackbarControl::verticalTickPosition position);

			~VerticalTrackbarControlStyles() = default;
		};
	}
}
