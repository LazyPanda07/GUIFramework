#pragma once

#include "BaseGUIFrameworkException.h"

namespace gui_framework
{
	namespace exceptions
	{
		class GUI_FRAMEWORK_API CantLoadModuleException : public BaseGUIFrameworkException
		{
		public:
			CantLoadModuleException(const std::string& moduleName);

			~CantLoadModuleException() = default;
		};
	}
}
