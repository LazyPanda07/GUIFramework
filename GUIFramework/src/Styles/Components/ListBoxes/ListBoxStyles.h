#pragma once

#include "core.h"
#include "Styles/DefaultStyles.h"

namespace gui_framework
{
	namespace styles
	{
		/// @brief Base class for list box styles
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
