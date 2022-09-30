#pragma once

#include "Core.h"
#include "Styles/DefaultStyles.h"

namespace gui_framework
{
	namespace styles
	{
		/// @brief Default RichEdit styles
		class GUI_FRAMEWORK_API DefaultRichEditStyles : public DefaultStyles
		{
		public:
			DefaultRichEditStyles(bool isMultiLine = false);

			~DefaultRichEditStyles() = default;
		};
	}
}
