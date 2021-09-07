#pragma once

#include "headers.h"

#include "JSONUtility.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief Unregister class that is used in SeparateWindow, ChildWindow, DialogBox, GroupBox
		/// @param className 
		GUI_FRAMEWORK_API_FUNCTION void unregisterClass(const std::wstring& className);

		/// @brief Append WinAPI style
		/// @param handle 
		/// @param newStyle 
		GUI_FRAMEWORK_API_FUNCTION void appendStyle(HWND handle, LONG_PTR newStyle);

		/// @brief Remove WinAPI style
		/// @param handle 
		/// @param styleToRemove 
		GUI_FRAMEWORK_API_FUNCTION void removeStyle(HWND handle, LONG_PTR styleToRemove);

		/// @brief Convert std::wstring to std::string
		/// @param stringToConvert 
		/// @param codepage stringToConvert codepage
		/// @return stringToConvert data as std::string
		/// @exception json::exceptions::WrongEncodingException 
		GUI_FRAMEWORK_API_FUNCTION std::string to_string(const std::wstring& stringToConvert, uint32_t codepage);

		/// @brief Convert std::string to std::wstring
		/// @param stringToConvert 
		/// @param codepage stringToConvert codepage
		/// @return stringToConvert data as std::wstring
		/// @exception json::exceptions::WrongEncodingException 
		GUI_FRAMEWORK_API_FUNCTION std::wstring to_wstring(const std::string& stringToConvert, uint32_t codepage);

		/// @brief Get handle to current executable
		/// @return 
		GUI_FRAMEWORK_API_FUNCTION HMODULE getCurrentModule();

		/// @brief Get string with \\ from raw string contructed path
		/// @param pathFromRawString 
		/// @return 
		GUI_FRAMEWORK_API_FUNCTION std::string getStringFromRawPath(const std::filesystem::path& pathFromRawString);

		/// @brief Load function from module
		/// @param onClick Output parameter for function load
		/// @param functionName Name of function in module
		/// @param moduleName Name of module in JSON array modules in gui_framework.json
		/// @exception CantFindFunctionFromModuleException 
		GUI_FRAMEWORK_API_FUNCTION void loadFunctionFromModule(std::function<void()>& onClick, const std::string& functionName, const std::string& moduleName);

		/// @brief Load function from module
		/// @param eventCallback Output parameter for function load
		/// @param functionName Name of function in module
		/// @param moduleName Name of module in JSON array modules in gui_framework.json
		/// @exception CantFindFunctionFromModuleException 
		GUI_FRAMEWORK_API_FUNCTION void loadEventCallbackFromModule(std::function<void(const std::wstring&)>& eventCallback, const std::string& functionName, const std::string& moduleName);

		/// @brief Make function with current build configuration compatibility
		/// @tparam T Type
		/// @param ...args Constructor arguments 
		/// @return Compatible smart pointer
		template<typename T, typename... Args>
		smartPointerType<T> make_smart_pointer(Args&&... args);
	}

	namespace __utility
	{
		GUI_FRAMEWORK_API_FUNCTION void changeClassName(json::utility::objectSmartPointer<json::utility::jsonObject>& object, const std::string& className);

		GUI_FRAMEWORK_API_FUNCTION void throwNotImplementedException(std::string_view methodName, std::string_view className);
	}
}

template<typename T, typename... Args>
inline smartPointerType<T> gui_framework::utility::make_smart_pointer(Args&&... args)
{
	if constexpr (std::is_same_v<std::unique_ptr<T>, smartPointerType<T>>)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}
	else if constexpr (std::is_same_v<std::shared_ptr<T>, smartPointerType<T>>)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}
