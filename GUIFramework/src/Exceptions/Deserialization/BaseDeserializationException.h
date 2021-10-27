#pragma once

#include "Exceptions/BaseGUIFrameworkException.h"

namespace gui_framework
{
	namespace exceptions
	{
		namespace deserialization
		{
			/// @brief Base class for all deserialize exceptions
			class GUI_FRAMEWORK_API BaseDeserializationException : public BaseGUIFrameworkException
			{
			public:
				BaseDeserializationException(const std::string& exceptionMessage, std::string_view fileName, std::string_view methodName, int line);

				virtual ~BaseDeserializationException() = default;
			};
		}
	}
}
