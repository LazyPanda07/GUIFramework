#pragma once

#include "headers.h"
#include "Styles/DefaultStyles.h"

namespace gui_framework
{
	namespace styles
	{
		/// @brief ListView styles
		class GUI_FRAMEWORK_API ListViewStyles : public DefaultStyles
		{
		protected:
			ListViewStyles() = default;

		public:
			ListViewStyles(const ListViewStyles& listViewStyles);

			virtual ~ListViewStyles() = default;
		};
	}
}
