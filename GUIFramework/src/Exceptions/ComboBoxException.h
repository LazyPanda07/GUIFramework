#pragma once

#include "BaseGUIFrameworkException.h"

namespace gui_framework
{
	namespace exceptions
	{
		class ComboBoxException : public BaseGUIFrameworkException
		{
		public:
			ComboBoxException(const std::string& method, LRESULT errorCode, const std::string_view& additionalDescription = "");

			~ComboBoxException() = default;
		};
	}
}
