#pragma once

#include "pch.h"

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
	}
}

template<typename T, typename... Args>
smartPointerType<T> gui_framework::utility::make_smart_pointer(Args&&... args)
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
