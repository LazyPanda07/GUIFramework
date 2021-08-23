#pragma once

#include "headers.h"
#include "BaseGUIFrameworkException.h"

namespace gui_framework
{
	namespace exceptions
	{
		/// @brief Throws by not implemented methods
		class NotImplemented : public BaseGUIFrameworkException
		{
		public:
			NotImplemented(const std::string& methodName, const std::string& className);

			~NotImplemented() = default;
		};
	}
}
