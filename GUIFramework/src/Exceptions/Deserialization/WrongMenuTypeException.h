#pragma once

#include "BaseDeserializationException.h"

namespace gui_framework
{
	namespace exceptions
	{
		namespace deserialization
		{
			class GUI_FRAMEWORK_API WrongMenuTypeException : public BaseDeserializationException
			{
			public:
				WrongMenuTypeException(const std::string& type);

				~WrongMenuTypeException() = default;
			};
		}
	}
}
