#pragma once

#include "headers.h"
#include "BaseWindow.h"

namespace gui_framework
{
	/// @brief Base class for all nested windows
	class GUI_FRAMEWORK_API BaseChildWindow : public BaseWindow
	{
	public:
		BaseChildWindow(const std::wstring& className, const std::wstring& windowName, const utility::ComponentSettings& settings, BaseComponent* parent, const std::string& windowFunctionName = "");

		virtual ~BaseChildWindow() = default;
	};
}
