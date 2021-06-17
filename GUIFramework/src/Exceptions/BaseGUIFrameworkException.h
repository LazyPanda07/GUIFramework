#pragma once

#include "pch.h"
#include "ExceptionConstants.h"

namespace gui_framework
{
	namespace exceptions
	{
		/// @brief Base class for all GUIFramework exceptions
		class GUI_FRAMEWORK_API BaseGUIFrameworkException : public std::runtime_error
		{
		public:
			BaseGUIFrameworkException(const std::string& exceptionMessage);

			virtual ~BaseGUIFrameworkException() = default;
		};
	}
}
