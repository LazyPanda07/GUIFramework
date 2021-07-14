#pragma once

#include "Styles/DefaultStyles.h"

namespace gui_framework
{
	namespace styles
	{
		class GUI_FRAMEWORK_API ListBoxStyles : public DefaultStyles
		{
		protected:
			ListBoxStyles() = default;

		public:
			ListBoxStyles(const ListBoxStyles& listBoxStyles);

			virtual ~ListBoxStyles() = default;
		};
	}
}
