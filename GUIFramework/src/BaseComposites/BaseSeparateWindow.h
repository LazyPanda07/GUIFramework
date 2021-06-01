#pragma once

#include "BaseWindow.h"

namespace gui_framework
{
	class BaseSeparateWindow : public BaseWindow
	{
	public:
		/// @brief Create new separate window
		/// @param windowFunctionName Value that you pass in CREATE_DEFAULT_SEPARATE_WINDOW_FUNCTION macro
		/// @exception gui_framework::exceptions::AlreadyRegisteredClassNameException
		BaseSeparateWindow(const std::wstring& className, const std::wstring& titleName, const utility::ComponentSettings& settings, const std::string& windowFunctionName);

		virtual ~BaseSeparateWindow() = default;
	};
}
