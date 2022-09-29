#pragma once

#include "core.h"
#include "TrackbarControlStyles.h"
#include "Components/Trackbars/VerticalTrackbarControl.h"

namespace gui_framework
{
	namespace styles
	{
		/// @brief VerticalTrackbarControl styles
		class GUI_FRAMEWORK_API VerticalTrackbarControlStyles : public TrackbarControlStyles
		{
		public:
			VerticalTrackbarControlStyles(VerticalTrackbarControl::verticalTickPosition position);

			~VerticalTrackbarControlStyles() = default;
		};
	}
}
