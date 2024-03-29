#pragma once

/// @file GUIFrameworkConstants.h

#include <string>
#include <cstdint>
#include <memory>

#include <CommCtrl.h>
#include <Richedit.h>

namespace gui_framework
{
	namespace standard_classes
	{
		inline const std::wstring button = WC_BUTTONW;
		inline const std::wstring editControl = WC_EDITW;
		inline const std::wstring staticControl = WC_STATICW;
		inline const std::wstring comboBox = WC_COMBOBOXW;
		inline const std::wstring listBox = WC_LISTBOXW;
		inline const std::wstring richEdit = MSFTEDIT_CLASS;
		inline const std::wstring tabControl = WC_TABCONTROLW;
		inline const std::wstring listView = WC_LISTVIEWW;
		inline const std::wstring progressBar = PROGRESS_CLASSW;
		inline const std::wstring trackbarControl = TRACKBAR_CLASSW;
		inline const std::wstring scrollBar = WC_SCROLLBARW;
	}

	namespace standard_menu_items
	{
		inline const std::string dropDownMenuItem = "DropDown";
		inline const std::string menuItem = "MenuItem";
	}

	namespace standard_sizes
	{
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

		inline const std::string usingCreatorsSetting = "usingCreators";
		inline const std::string usingDeserializersSetting = "usingDeserializers";
		inline const std::string threadsCountSetting = "threadsCount";
		inline const std::string usingNotImplementedExceptions = "usingNotImplementedExceptions";
		inline const std::string usingExtendedExceptions = "usingExtendedExceptions";
		inline const std::string modulesSetting = "modules";
		inline const std::string moduleNameSetting = "moduleName";
		inline constexpr std::string_view pathToModuleSettings = "pathToModule";
	}

	namespace libraries
	{
		inline constexpr std::wstring_view msftEditLibrary = L"MsftEdit.dll";
	}

	/// @brief Default on click signature
	using onClickSignature = void(*)();

	/// @brief Default on destroy signature. Called before window is destroyed
	using onDestroySignature = void(*)();

	/// @brief Default on close signature. Worked only in BaseSeparateWindow subclasses. Called if user pressed close button
	using onCloseSignature = bool(*)();
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
