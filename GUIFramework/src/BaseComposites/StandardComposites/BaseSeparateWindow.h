#pragma once

#include "BaseWindow.h"

namespace gui_framework
{
	/// @brief Base class for separate windows
	class GUI_FRAMEWORK_API BaseSeparateWindow : public BaseWindow
	{
	public:
		/// @brief Create new separate window
		BaseSeparateWindow(const std::wstring& className, const std::wstring& titleName, const utility::ComponentSettings& settings, const std::string& windowFunctionName);

		virtual ~BaseSeparateWindow() = default;
	};
}
