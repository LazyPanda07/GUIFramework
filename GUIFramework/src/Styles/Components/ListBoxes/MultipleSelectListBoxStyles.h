#pragma once

#include "headers.h"
#include "ListBoxStyles.h"

namespace gui_framework
{
	namespace styles
	{
		/// @brief MultipleSelectListBox styles
		class GUI_FRAMEWORK_API MultipleSelectListBoxStyles : public ListBoxStyles
		{
		public:
			MultipleSelectListBoxStyles(bool isSorting = false);

			~MultipleSelectListBoxStyles() = default;
		};
	}
}
