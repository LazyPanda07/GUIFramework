#pragma once

#include "Styles/Components/ListViews/ListViewStyles.h"

namespace gui_framework
{
	namespace styles
	{
		class GUI_FRAMEWORK_API IconListViewStyles : public ListViewStyles
		{
		public:
			IconListViewStyles(utility::iconListViewType type);

			~IconListViewStyles() = default;
		};
	}
}
