#pragma once

#include "pch.h"

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

		template<typename T, typename... Args>
		GUI_FRAMEWORK_API_FUNCTION smartPointerType<T> make_smart_pointer(Args&&... args);
	}
}

template<typename T, typename... Args>
smartPointerType<T> gui_framework::utility::make_smart_pointer(Args&&... args)
{
	if constexpr (std::is_same_v<std::unique_ptr<T>, smartPointerType>)
	{
		return std::make_unique<T>(std::forward<Args>(args...));
	}
	else if constexpr (std::is_same_v<std::shared_ptr<T>, smartPointerType>)
	{
		return std::make_shared<T>(std::forward<Args>(args...));
	}

	static_assert(false, "Wrong smartPointerType");
}
