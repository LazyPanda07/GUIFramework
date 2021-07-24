#pragma once

#include "pch.h"
#include "Interfaces/Styles/IStyles.h"

namespace gui_framework
{
	namespace styles
	{
		/// @brief Provides default styles for all windows
		class GUI_FRAMEWORK_API DefaultStyles : public interfaces::IStyles
		{
		public:
			DefaultStyles();

			~DefaultStyles() = default;
		};
	}
}
