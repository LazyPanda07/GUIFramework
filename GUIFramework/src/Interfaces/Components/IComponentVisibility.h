#pragma once

#include "headers.h"

namespace gui_framework
{
	namespace interfaces
	{
		class GUI_FRAMEWORK_API IComponentVisibility
		{
		protected:
			HWND componentVisibilityHandle;

		public:
			IComponentVisibility(HWND componentVisibilityHandle);

			void show() const;

			void hide() const;

			virtual ~IComponentVisibility() = default;
		};
	}
}
