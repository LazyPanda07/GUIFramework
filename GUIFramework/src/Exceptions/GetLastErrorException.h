#pragma once

#include "BaseGUIFrameworkException.h"

namespace gui_framework
{
	namespace exceptions
	{
		class GetLastErrorException : public BaseGUIFrameworkException
		{
		public:
			GetLastErrorException(DWORD errorCode);

			~GetLastErrorException() = default;
		};
	}
}
