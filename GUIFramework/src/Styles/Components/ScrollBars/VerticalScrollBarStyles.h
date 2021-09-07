#pragma once

#include "ScrollBarStyles.h"

namespace gui_framework
{
	namespace styles
	{
		/// @brief VerticalScrollBar styles
		class GUI_FRAMEWORK_API VerticalScrollBarStyles : virtual public ScrollBarStyles
		{
		public:
			VerticalScrollBarStyles();

			virtual ~VerticalScrollBarStyles() = default;
		};
	}
}
