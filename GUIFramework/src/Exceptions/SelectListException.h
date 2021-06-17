#pragma once

#include "BaseGUIFrameworkException.h"

namespace gui_framework
{
	namespace exceptions
	{
		/// @brief Exception for all list classes exceptions
		class GUI_FRAMEWORK_API SelectListException : public BaseGUIFrameworkException
		{
		public:
			SelectListException(const std::string& method, LRESULT errorCode, const std::string_view& additionalDescription = "");

			~SelectListException() = default;
		};
	}
}
