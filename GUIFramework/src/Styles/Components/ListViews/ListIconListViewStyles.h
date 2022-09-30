#pragma once

#include "Styles/Components/ListViews/ListListViewStyles.h"
#include "Utility/Holders/LoadableHolders/BaseLoadableHolder.h"

namespace gui_framework
{
	namespace styles
	{
		/// @brief ListIconListView styles
		class GUI_FRAMEWORK_API ListIconListViewStyles : public ListListViewStyles
		{
		public:
			ListIconListViewStyles(utility::iconListViewType type);

			~ListIconListViewStyles() = default;
		};
	}
}
