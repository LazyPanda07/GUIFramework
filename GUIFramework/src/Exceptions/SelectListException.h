#pragma once

#include "BaseGUIFrameworkException.h"

namespace gui_framework
{
	namespace exceptions
	{
		class SelectListException : public BaseGUIFrameworkException
		{
		public:
			SelectListException(const std::string& method, LRESULT errorCode, const std::string_view& additionalDescription = "");

			~SelectListException() = default;
		};
	}
}
