#pragma once

#include "BaseGUIFrameworkException.h"

namespace gui_framework
{
	namespace exceptions
	{
		/// @brief Can't find CREATE_DEFAULT_WINDOW_FUNCTION macro for specific window
		class CantFindSeparateWindowFunctionException : public BaseGUIFrameworkException
		{
		public:
			CantFindSeparateWindowFunctionException(const std::string& functionName);

			~CantFindSeparateWindowFunctionException() = default;
		};
	}
}
