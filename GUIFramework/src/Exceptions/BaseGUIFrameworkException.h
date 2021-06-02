#pragma once

#include "pch.h"

namespace gui_framework
{
	namespace exceptions
	{
		/// @brief Base class for all GUIFramework exceptions
		class BaseGUIFrameworkException : public std::runtime_error
		{
		public:
			BaseGUIFrameworkException(const std::string& exceptionMessage);

			virtual ~BaseGUIFrameworkException() = default;
		};
	}
}
