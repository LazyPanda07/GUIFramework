#pragma once

#include "BaseGUIFrameworkException.h"

namespace gui_framework
{
	namespace exceptions
	{
		class GUI_FRAMEWORK_API CantGetUIThreadId : public BaseGUIFrameworkException
		{
		public:
			CantGetUIThreadId(std::string_view fileName, std::string_view methodName, int line);

			~CantGetUIThreadId() = default;
		};
	}
}
