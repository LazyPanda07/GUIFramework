#pragma once

#include "ListViewStyles.h"

namespace gui_framework
{
	namespace styles
	{
		/// @brief ListListView styles
		class GUI_FRAMEWORK_API ListListViewStyles : public ListViewStyles
		{
		protected:
			ListListViewStyles();

		public:
			ListListViewStyles(const ListListViewStyles& listViewStyles);

			virtual ~ListListViewStyles() = default;
		};
	}
}
