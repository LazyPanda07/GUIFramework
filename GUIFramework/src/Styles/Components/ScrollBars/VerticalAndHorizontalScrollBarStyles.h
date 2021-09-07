#pragma once

#include "VerticalScrollBarStyles.h"
#include "HorizontalScrollBarStyles.h"

namespace gui_framework
{
	namespace styles
	{
		class GUI_FRAMEWORK_API VerticalAndHorizontalScrollBarStyles :
			public VerticalScrollBarStyles,
			public HorizontalScrollBarStyles
		{
		public:
			VerticalAndHorizontalScrollBarStyles() = default;

			~VerticalAndHorizontalScrollBarStyles() = default;
		};
	}
}
