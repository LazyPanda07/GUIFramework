#pragma once

#include "pch.h"
#include "TrackbarControlStyles.h"
#include "Components/Trackbars/HorizontalTrackbarControl.h"

namespace gui_framework
{
	namespace styles
	{
		/// @brief HorizontalTrackbarControl styles
		class GUI_FRAMEWORK_API HorizontalTrackbarControlStyles : public TrackbarControlStyles
		{
		public:
			HorizontalTrackbarControlStyles(HorizontalTrackbarControl::horizontalTickPosition position);

			~HorizontalTrackbarControlStyles() = default;
		};
	}
}
