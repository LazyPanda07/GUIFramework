#pragma once

#include "Styles/DefaultStyles.h"

namespace gui_framework
{
	namespace styles
	{
		class GUI_FRAMEWORK_API ListViewStyles : public DefaultStyles
		{
		protected:
			ListViewStyles() = default;

		public:
			ListViewStyles(const ListViewStyles& buttonStyles);

			virtual ~ListViewStyles() = default;
		};
	}
}
