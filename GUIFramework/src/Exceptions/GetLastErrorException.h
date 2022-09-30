#pragma once

#include "BaseGUIFrameworkException.h"

namespace gui_framework
{
	namespace exceptions
	{
		/// @brief Exception that receive error code from GetLastError function
		class GUI_FRAMEWORK_API GetLastErrorException : public BaseGUIFrameworkException
		{
		public:
			GetLastErrorException(DWORD errorCode, std::string_view fileName, std::string_view methodName, int line);

			~GetLastErrorException() = default;
		};
	}
}
