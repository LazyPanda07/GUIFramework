#pragma once

#include <string>
#include <cstdint>

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
		inline constexpr std::wstring_view staticControl = L"Static";
		inline constexpr std::wstring_view comboBox = L"ComboBox";
	}

	namespace standard_sizes
	{
		inline constexpr uint16_t buttonWidth = 200;
		inline constexpr uint16_t buttonHeight = 20;

		inline constexpr uint16_t editControlWidth = 200;
		inline constexpr uint16_t editControlHeight = 20;

		inline constexpr uint16_t staticControlWidth = 200;
		inline constexpr uint16_t staticControlHeight = 40;

		inline constexpr uint16_t comboBoxAdditionalWidth = 10;
	}

	namespace settings
	{
		inline constexpr std::string_view settingsJSONFile = "gui_framework.json";
	}
}
