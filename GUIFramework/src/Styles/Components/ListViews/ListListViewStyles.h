#pragma once

#include "ListViewStyles.h"

namespace gui_framework
{
	namespace styles
	{
		class GUI_FRAMEWORK_API ListListViewStyles : public ListViewStyles
		{
		protected:
			ListListViewStyles() = default;

		public:
			ListListViewStyles(const ListListViewStyles& buttonStyles);

			virtual ~ListListViewStyles() = default;
		};
	}
}