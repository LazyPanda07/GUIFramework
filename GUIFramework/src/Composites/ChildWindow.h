#pragma once

#include "BaseComposites/StandardComposites/BaseChildWindow.h"
#include "BaseComposites/BaseResizableComposite.h"

namespace gui_framework
{
	/// @brief Standard child window
	class GUI_FRAMEWORK_API ChildWindow :
		public BaseResizableComposite,
		public BaseChildWindow
	{
	private:
		LRESULT preWindowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed) override;

	public:
		ChildWindow(const std::wstring& className, const std::wstring& windowName, const utility::ComponentSettings& settings, BaseComponent* parent, const std::string& windowFunctionName = "");

		~ChildWindow() = default;
	};
}
