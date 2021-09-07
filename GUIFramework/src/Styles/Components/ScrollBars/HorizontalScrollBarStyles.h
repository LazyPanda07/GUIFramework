#pragma once

#include "ScrollBarStyles.h"

namespace gui_framework
{
	namespace styles
	{
		/// @brief HorizontalScrollBar styles
		class GUI_FRAMEWORK_API HorizontalScrollBarStyles : virtual public ScrollBarStyles
		{
		public:
			HorizontalScrollBarStyles();

			virtual ~HorizontalScrollBarStyles() = default;
		};
	}
}
