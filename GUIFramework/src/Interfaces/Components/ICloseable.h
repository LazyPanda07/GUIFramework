#pragma once

#include "headers.h"

namespace gui_framework
{
	namespace interfaces
	{
		class GUI_FRAMEWORK_API ICloseable
		{
		protected:
			HWND closeableHandle;

		public:
			ICloseable(HWND closeableHandle);

			bool close(int exitCode);

			virtual ~ICloseable() = default;
		};
	}
}
