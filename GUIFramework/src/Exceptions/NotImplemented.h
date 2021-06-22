#pragma once

#include "BaseGUIFrameworkException.h"

namespace gui_framework
{
	namespace exceptions
	{
		class NotImplemented : public BaseGUIFrameworkException
		{
		public:
			NotImplemented(const std::string& methodName, const std::string& className);

			~NotImplemented() = default;
		};
	}
}
