#pragma once

#include "pch.h"

#include <string>
#include <cstdint>
#include <memory>

#include <Richedit.h>

namespace gui_framework
{
	namespace standard_classes
	{
		inline constexpr std::wstring_view button = WC_BUTTONW;
		inline constexpr std::wstring_view editControl = WC_EDITW;
		inline constexpr std::wstring_view staticControl = WC_STATICW;
		inline constexpr std::wstring_view comboBox = WC_COMBOBOXW;
		inline constexpr std::wstring_view listBox = WC_LISTBOXW;
		inline constexpr std::wstring_view richEdit = MSFTEDIT_CLASS;
		inline constexpr std::wstring_view tabControl = WC_TABCONTROLW;
		inline constexpr std::wstring_view listView = WC_LISTVIEWW;
		inline constexpr std::wstring_view progressBar = PROGRESS_CLASSW;
		inline constexpr std::wstring_view trackbarControl = TRACKBAR_CLASSW;
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

		inline constexpr uint16_t checkBoxWidth = 200;
		inline constexpr uint16_t checkBoxHeight = 20;

		inline constexpr uint16_t editControlWidth = 200;
		inline constexpr uint16_t editControlHeight = 20;

		inline constexpr uint16_t staticControlWidth = 200;
		inline constexpr uint16_t staticControlHeight = 40;

		inline constexpr uint16_t comboBoxAdditionalWidth = 10;

		inline constexpr uint16_t listBoxAdditionalWidth = 20;

		inline constexpr uint16_t dialogBoxBuilderMinWidth = 300;
		inline constexpr uint16_t dialogBoxBuilderMinHeight = 200;

		inline constexpr uint16_t defaultImagesCount = 16;

		inline constexpr uint16_t largeIconWidth = 32;
		inline constexpr uint16_t largeIconHeight = 32;

		inline constexpr uint16_t smallIconWidth = 16;
		inline constexpr uint16_t smallIconHeight = 16;

		inline constexpr uint16_t additionalListViewReportColumnWidth = 10;
	}

	namespace json_settings
	{
		inline constexpr std::string_view settingsJSONFile = "gui_framework.json";

		inline const std::string settingsObject = "settings";

		inline const std::string usingDefaultCreatorsSetting = "usingDefaultCreators";
		inline const std::string threadsCountSetting = "threadsCount";
		inline const std::string modulesSetting = "modules";
		inline const std::string moduleNameSetting = "moduleName";
		inline constexpr std::string_view pathToModuleSettings = "pathToModule";
	}

	namespace libraries
	{
		inline constexpr std::wstring_view msftEditLibrary = L"MsftEdit.dll";
	}

	namespace hotkeys
	{
		enum class additionalKey
		{
			alt,
			control,
			shift = 4
		};
	}

	inline constexpr std::string_view guiFrameworkVersion = "0.7.5-beta";

	/// @brief Default on click signature
	using onClickSignature = void(*)();
}

#define IMPLEMENT_SERIALIZABLE_FUNCTION extern "C" __declspec(dllexport) 

#ifdef GUI_FRAMEWORK_DLL
#define GUI_FRAMEWORK_API __declspec(dllexport)
#define GUI_FRAMEWORK_API_FUNCTION extern "C" __declspec(dllexport)
#define JSON_DLL
#define THREAD_POOL_DLL

/// @brief Compatible smart pointer type
template<typename T>
using smartPointerType = std::shared_ptr<T>;

#pragma warning(disable: 4251)
#pragma warning(disable: 4275)
#pragma warning(disable: 4190)
#else
#define GUI_FRAMEWORK_API
#define GUI_FRAMEWORK_API_FUNCTION

/// @brief Compatible smart pointer type
template<typename T>
using smartPointerType = std::unique_ptr<T>;

#endif // GUI_FRAMEWORK_DLL
