#pragma once

#include "BaseGUIFrameworkException.h"

namespace gui_framework
{
	namespace exceptions
	{
		class AlreadyRegisteredclassNameException : public BaseGUIFrameworkException
		{
		public:
			AlreadyRegisteredclassNameException();

			~AlreadyRegisteredclassNameException() = default;
		};
	}
}
