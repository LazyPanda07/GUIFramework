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
		inline constexpr std::wstring_view editControl = L"Edit";
	}

	namespace standard_sizes
	{
		inline constexpr int buttonWidth = 200;
		inline constexpr int buttonHeight = 20;

		inline constexpr int editControlWidth = 200;
		inline constexpr int editControlHeight = 20;
	}

	namespace settings
	{
		inline constexpr std::string_view settingsJSONFile = "gui_framework.json";
	}
}
