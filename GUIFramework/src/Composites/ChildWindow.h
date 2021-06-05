#pragma once

#include "BaseComposites/BaseChildWindow.h"

namespace gui_framework
{
	class ChildWindow : public BaseChildWindow
	{
	public:
		ChildWindow(const std::wstring& className, const std::wstring& windowName, const utility::ComponentSettings& settings, BaseComponent* parent, const std::string& windowFunctionName = "");

		~ChildWindow() = default;
	};
}
