#pragma once

#include "BaseGUIFrameworkException.h"

namespace gui_framework
{
	namespace exceptions
	{
		/// @brief Trying to register same window class
		class AlreadyRegisteredClassNameException : public BaseGUIFrameworkException
		{
		public:
			AlreadyRegisteredClassNameException();

			~AlreadyRegisteredClassNameException() = default;
		};
	}
}
