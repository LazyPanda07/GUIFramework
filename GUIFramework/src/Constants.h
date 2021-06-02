#pragma once

#include <string>

namespace gui_framework
{
	namespace exception_messages
	{
		inline constexpr std::string_view alreadyRegisteredClassName = "This class name already registered";
	}

	namespace standard_classes
	{
		inline constexpr std::wstring_view button = L"Button";
	}

	namespace settings
	{
		inline constexpr std::string_view settingsJSONFile = "gui_framework.json";
	}
}
