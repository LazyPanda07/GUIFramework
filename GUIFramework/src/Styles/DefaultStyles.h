#pragma once

#include "Interfaces/Styles/IStyles.h"

namespace gui_framework
{
	namespace styles
	{
		class GUI_FRAMEWORK_API DefaultStyles : public interfaces::IStyles
		{
		public:
			DefaultStyles();

			~DefaultStyles() = default;
		};
	}
}
