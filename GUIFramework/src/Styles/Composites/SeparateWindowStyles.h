#pragma once

#include "headers.h"
#include "Styles/DefaultStyles.h"

namespace gui_framework
{
	namespace styles
	{
		/// @brief SeparateWindow styles
		class GUI_FRAMEWORK_API SeparateWindowStyles : public DefaultStyles
		{
		public:
			SeparateWindowStyles(bool maximize = false, bool minimize = false);

			~SeparateWindowStyles() = default;
		};
	}
}
