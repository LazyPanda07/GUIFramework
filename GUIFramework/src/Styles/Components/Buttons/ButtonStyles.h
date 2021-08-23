#pragma once

#include "headers.h"
#include "Styles/DefaultStyles.h"

namespace gui_framework
{
	namespace styles
	{
		/// @brief Base class for button styles
		class GUI_FRAMEWORK_API ButtonStyles : public DefaultStyles
		{
		protected:
			ButtonStyles() = default;

		public:
			ButtonStyles(const ButtonStyles& buttonStyles);

			virtual ~ButtonStyles() = default;
		};
	}
}
