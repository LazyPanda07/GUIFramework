#pragma once

#include "BaseGUIFrameworkException.h"

namespace gui_framework
{
	namespace exceptions
	{
		/// @brief Throws by setOn... methods
		class GUI_FRAMEWORK_API CantFindFunctionFromModuleException : public BaseGUIFrameworkException
		{
		public:
			CantFindFunctionFromModuleException(const std::string& functionName, const std::string& moduleName, std::string_view fileName, std::string_view methodName, int line);

			~CantFindFunctionFromModuleException() = default;
		};
	}
}
