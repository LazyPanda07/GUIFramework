#pragma once

#include "core.h"
#include "BaseGUIFrameworkException.h"

namespace gui_framework
{
	namespace exceptions
	{
		/// @brief Exception for all list classes exceptions
		class GUI_FRAMEWORK_API SelectListException : public BaseGUIFrameworkException
		{
		public:
			SelectListException(const std::string& method, LRESULT errorCode, std::string_view fileName, std::string_view methodName, int line, std::string_view additionalDescription = "");

			~SelectListException() = default;
		};
	}
}
