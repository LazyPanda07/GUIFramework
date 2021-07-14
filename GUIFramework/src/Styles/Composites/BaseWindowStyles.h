#pragma once

#include "Styles/DefaultStyles.h"

namespace gui_framework
{
	namespace styles
	{
		class GUI_FRAMEWORK_API BaseWindowStyles : public DefaultStyles
		{
		public:
			BaseWindowStyles(bool maximize = false, bool minimize = false);

			~BaseWindowStyles() = default;
		};
	}
}
