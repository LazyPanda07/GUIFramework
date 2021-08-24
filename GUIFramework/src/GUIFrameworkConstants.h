#pragma once

#include "headers.h"

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

	namespace serialized_classes
	{
		inline const std::string button = "Button";
		inline const std::string checkBox = "CheckBox";
		inline const std::string imageButton = "ImageButton";
		inline const std::string editControl = "Edit";
		inline const std::string richEdit = "RichEdit";
		inline const std::string staticControl = "Static";
		inline const std::string separateWindow = "SeparateWindow";
		inline const std::string childWindow = "ChildWindow";
		inline const std::string tabControl = "TabConrol";
		inline const std::string groupBox = "GroupBox";
		inline const std::string progressBar = "ProgressBar";
		inline const std::string infiniteProgressBar = "InfiniteProgressBar";
		inline const std::string dropDownComboBox = "DropDownComboBox";
		inline const std::string dropDownListComboBox = "DropDownListComboBox";
		inline const std::string simpleComboBox = "SimpleComboBox";
		inline const std::string listBox = "ListBox";
		inline const std::string multipleSelectListBox = "MultipleSelectListBox";
		inline const std::string iconListView = "IconListView";
		inline const std::string listIconListView = "ListIconListView";
		inline const std::string textListView = "TextListView";
		inline const std::string listTextListView = "ListTextListView";
		inline const std::string textIconListView = "TextIconListView";
		inline const std::string listTextIconListView = "ListTextIconListView";
		inline const std::string horizontalTrackbarControl = "HorizontalTrackbarControl";
		inline const std::string verticalTrackbarControl = "VerticalTrackbarControl";
	}

	namespace serialized_creation_type
	{
		inline const std::string baseComposite = "BaseComposite";
		inline const std::string baseWindow = "BaseWindow";
		inline const std::string baseSeparateWindow = "BaseSeparateWindow";
		inline const std::string baseChildWindow = "BaseChildWindow";
		inline const std::string baseDialogBox = "BaseDialogBox";
		inline const std::string separateWindow = "SeparateWindow";
		inline const std::string childWindow = "ChildWindow";
		inline const std::string dialogBox = "DialogBox";
		inline const std::string groupBox = "GroupBox";
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

		inline const uint16_t largeIconWidth = GetSystemMetrics(SM_CXICON);
		inline const uint16_t largeIconHeight = GetSystemMetrics(SM_CYICON);

		inline const uint16_t smallIconWidth = GetSystemMetrics(SM_CXSMICON);
		inline const uint16_t smallIconHeight = GetSystemMetrics(SM_CYSMICON);

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

	inline constexpr std::string_view guiFrameworkVersion = "0.8.2-beta";

	/// @brief Default on click signature
	using onClickSignature = void(*)();
}

/// @brief Insert this macro before serializable function declaration and implementation
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
