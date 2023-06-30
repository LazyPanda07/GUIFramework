#pragma once

#include "Styles/Components/ListViews/ListViewStyles.h"
#include "Holders/LoadableHolders/BaseLoadableHolder.h"

namespace gui_framework
{
	namespace styles
	{
		/// @brief IconListView styles
		class GUI_FRAMEWORK_API IconListViewStyles : public ListViewStyles
		{
		public:
			IconListViewStyles(utility::iconListViewType type);

			~IconListViewStyles() = default;
		};
	}
}
