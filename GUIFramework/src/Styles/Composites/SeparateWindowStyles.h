#pragma once

#include "Styles/DefaultStyles.h"

namespace gui_framework
{
	namespace styles
	{
		class GUI_FRAMEWORK_API SeparateWindowStyles : public DefaultStyles
		{
		public:
			SeparateWindowStyles(bool maximize = false, bool minimize = false);

			~SeparateWindowStyles() = default;
		};
	}
}
