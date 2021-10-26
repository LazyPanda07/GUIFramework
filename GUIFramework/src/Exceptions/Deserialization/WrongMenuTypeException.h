#pragma once

#include "BaseDeserializationException.h"

namespace gui_framework
{
	namespace exceptions
	{
		namespace deserialization
		{
			/// @brief Throws by SeparateWindowDeserializer during deserialize if JSON has wrong itemType value
			class GUI_FRAMEWORK_API WrongMenuTypeException : public BaseDeserializationException
			{
			public:
				WrongMenuTypeException(const std::string& type);

				~WrongMenuTypeException() = default;
			};
		}
	}
}
