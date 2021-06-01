#pragma once

#include "BaseWindow.h"

namespace gui_framework
{
	class BaseChildWindow : public BaseWindow
	{
	public:
		BaseChildWindow(const std::wstring& className, const std::wstring& windowName, const utility::ComponentSettings& settings, BaseComponent* parent, const std::string& windowFunctionName = "");

		virtual ~BaseChildWindow() = default;
	};
}
