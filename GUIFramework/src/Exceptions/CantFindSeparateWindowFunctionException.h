#pragma once

#include "BaseGUIFrameworkException.h"

namespace gui_framework
{
	namespace exceptions
	{
		class CantFindSeparateWindowFunctionException : public BaseGUIFrameworkException
		{
		public:
			CantFindSeparateWindowFunctionException(const std::string& functionName);

			~CantFindSeparateWindowFunctionException() = default;
		};
	}
}
