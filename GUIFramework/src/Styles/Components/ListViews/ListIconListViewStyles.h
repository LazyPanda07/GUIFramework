#pragma once

#include "Styles/Components/ListViews/ListListViewStyles.h"

namespace gui_framework
{
	namespace styles
	{
		class GUI_FRAMEWORK_API ListIconListViewStyles : public ListListViewStyles
		{
		public:
			ListIconListViewStyles(utility::iconListViewType type);

			~ListIconListViewStyles() = default;
		};
	}
}
