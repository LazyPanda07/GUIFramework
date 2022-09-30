#pragma once

#include "BaseGUIFrameworkException.h"

namespace gui_framework
{
	namespace exceptions
	{
		/// @brief Throws by not implemented methods
		class NotImplemented : public BaseGUIFrameworkException
		{
		public:
			NotImplemented(std::string_view methodName, std::string_view className, std::string_view fileName, int line);

			~NotImplemented() = default;
		};
	}
}
