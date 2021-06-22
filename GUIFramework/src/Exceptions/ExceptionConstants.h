#pragma once

#include <string>

namespace gui_framework
{
	namespace exception_messages
	{
		inline constexpr std::string_view alreadyRegisteredClassName = "This class name already registered";

		inline constexpr std::string_view notEnoughSpace = "Insufficient space is available to store the new string";

		inline constexpr std::string_view notImplemented = "Method {} not implemented for {} class";
	}
}
