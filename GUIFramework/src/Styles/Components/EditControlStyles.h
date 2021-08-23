#pragma once

#include "headers.h"
#include "Styles/DefaultStyles.h"

namespace gui_framework
{
	namespace styles
	{
		/// @brief Edit control styles
		class GUI_FRAMEWORK_API EditControlStyles : public DefaultStyles
		{
		public:
			EditControlStyles(bool isMultiLine = false);

			~EditControlStyles() = default;
		};
	}
}
