#pragma once

#include "Core.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief Unregister class that is used in SeparateWindow, ChildWindow, DialogBox, GroupBox
		/// @param className 
		GUI_FRAMEWORK_API_FUNCTION void unregisterClass(std::wstring_view className);

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
		GUI_FRAMEWORK_API_FUNCTION std::string to_string(std::wstring_view stringToConvert, uint32_t codepage);

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

		/**
		 * @brief Get center X coordinate
		*/
		GUI_FRAMEWORK_API_FUNCTION int getCenterX(int width);

		/**
		 * @brief Get center Y coordinate
		*/
		GUI_FRAMEWORK_API_FUNCTION int getCenterY(int height);

		/// @brief Get current version of GUIFramework
		/// @return 
		GUI_FRAMEWORK_API_FUNCTION std::string getGUIFrameworkVersion();

		/// @brief Make function with current build configuration compatibility
		/// @tparam T Type
		/// @param ...args Constructor arguments 
		/// @return Compatible smart pointer
		template<typename T, typename... Args>
		smartPointerType<T> make_smart_pointer(Args&&... args);

		template<typename T>
		size_t getTypeHash();
	}

	namespace __utility
	{
		GUI_FRAMEWORK_API_FUNCTION void throwNotImplementedException(std::string_view methodName, std::string_view className);

		GUI_FRAMEWORK_API_FUNCTION std::string extendedException(const std::string& exceptionMessage, std::string_view fileName, std::string_view methodName, int line);

		GUI_FRAMEWORK_API_FUNCTION bool useOnClose(std::any topLevelWindow);
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

template<typename T>
inline size_t gui_framework::utility::getTypeHash()
{
	return typeid(T).hash_code();
}
