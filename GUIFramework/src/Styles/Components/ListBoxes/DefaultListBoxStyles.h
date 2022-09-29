#pragma once

#include "core.h"
#include "ListBoxStyles.h"

namespace gui_framework
{
	namespace styles
	{
		/// @brief Default class for ListBoxStyles
		class GUI_FRAMEWORK_API DefaultListBoxStyles : public ListBoxStyles
		{
		public:
			DefaultListBoxStyles(bool isSorting = false);

			~DefaultListBoxStyles() = default;
		};
	}
}
