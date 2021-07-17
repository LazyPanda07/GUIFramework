#pragma once

#include "pch.h"
#include "Styles/DefaultStyles.h"

namespace gui_framework
{
	namespace styles
	{
		/// @brief TrackbarControl styles
		class GUI_FRAMEWORK_API TrackbarControlStyles : public DefaultStyles
		{
		protected:
			TrackbarControlStyles() = default;

		public:
			TrackbarControlStyles(const TrackbarControlStyles& buttonStyles);

			virtual ~TrackbarControlStyles() = default;
		};
	}
}
