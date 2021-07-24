#pragma once

#include "pch.h"
#include "Styles/DefaultStyles.h"

namespace gui_framework
{
	namespace styles
	{
		/// @brief Base class for combo box styles
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
