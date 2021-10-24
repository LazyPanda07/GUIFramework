#pragma once

#include "Exceptions/BaseGUIFrameworkException.h"

namespace gui_framework
{
	namespace exceptions
	{
		namespace deserialization
		{
			class GUI_FRAMEWORK_API BaseDeserializationException : public BaseGUIFrameworkException
			{
			public:
				BaseDeserializationException(const std::string& exceptionMessage);

				virtual ~BaseDeserializationException() = default;
			};
		}
	}
}
