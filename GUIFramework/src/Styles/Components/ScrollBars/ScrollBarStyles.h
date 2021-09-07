#pragma once

#include "Styles/DefaultStyles.h"

namespace gui_framework
{
	namespace styles
	{
		/// @brief ScrollBar styles
		class GUI_FRAMEWORK_API ScrollBarStyles : public DefaultStyles
		{
		protected:
			ScrollBarStyles() = default;

		public:
			ScrollBarStyles(const ScrollBarStyles& scrollBarStyles);

			virtual ~ScrollBarStyles() = default;
		};
	}
}
