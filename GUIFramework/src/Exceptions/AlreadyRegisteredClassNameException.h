#pragma once

#include "BaseGUIFrameworkException.h"

namespace gui_framework
{
	namespace exceptions
	{
		class AlreadyRegisteredClassNameException : public BaseGUIFrameworkException
		{
		public:
			AlreadyRegisteredClassNameException();

			~AlreadyRegisteredClassNameException() = default;
		};
	}
}
