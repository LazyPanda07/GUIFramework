#pragma once

#include "BaseComposites/BaseChildWindow.h"
#include "BaseComposites/BaseResizableComposite.h"

namespace gui_framework
{
	class ChildWindow :
		public BaseResizableComposite,
		public BaseChildWindow
	{
	public:
		ChildWindow(const std::wstring& className, const std::wstring& windowName, const utility::ComponentSettings& settings, BaseComponent* parent, const std::string& windowFunctionName = "");

		~ChildWindow() = default;
	};
}
