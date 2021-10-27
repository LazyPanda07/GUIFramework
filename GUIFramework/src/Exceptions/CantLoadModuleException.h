#pragma once

#include "BaseGUIFrameworkException.h"

namespace gui_framework
{
	namespace exceptions
	{
		/// @brief Throws by GUIFramework::get(), GUIFramework::loadModule()
		class GUI_FRAMEWORK_API CantLoadModuleException : public BaseGUIFrameworkException
		{
		public:
			CantLoadModuleException(const std::string& moduleName, std::string_view fileName, std::string_view methodName, int line);

			~CantLoadModuleException() = default;
		};
	}
}
