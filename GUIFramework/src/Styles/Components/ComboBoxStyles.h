#pragma once

#include "Styles/DefaultStyles.h"

namespace gui_framework
{
	namespace styles
	{
		class GUI_FRAMEWORK_API ComboBoxStyles : public DefaultStyles
		{
		protected:
			ComboBoxStyles() = default;

		public:
			ComboBoxStyles(const ComboBoxStyles& combobBoxStyles);

			virtual ~ComboBoxStyles() = default;
		};
	}
}
