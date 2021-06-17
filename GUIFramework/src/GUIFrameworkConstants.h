#pragma once

#include <string>
#include <cstdint>

#include <Richedit.h>

namespace gui_framework
{
	namespace standard_classes
	{
		inline constexpr std::wstring_view button = L"Button";
		inline constexpr std::wstring_view editControl = L"Edit";
		inline constexpr std::wstring_view staticControl = L"Static";
		inline constexpr std::wstring_view comboBox = L"ComboBox";
		inline constexpr std::wstring_view listBox = L"ListBox";
		inline constexpr std::wstring_view richEdit = MSFTEDIT_CLASS;
	}

	namespace standard_menu_items
	{
		inline constexpr std::string_view dropDownMenuItem = "DropDown";
		inline constexpr std::string_view menuItem = "MenuItem";
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
		
		inline constexpr uint16_t listBoxAdditionalWidth = 20;

		inline constexpr uint16_t dialogBoxBuilderMinWidth = 300;
		inline constexpr uint16_t dialogBoxBuilderMinHeight = 200;
	}

	namespace settings
	{
		inline constexpr std::string_view settingsJSONFile = "gui_framework.json";

		inline const std::string threadsCountSetting = "threadsCount";
	}

	namespace libraries
	{
		inline constexpr std::wstring_view msftEditLibrary = L"MsftEdit.dll";
	}
}
