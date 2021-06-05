#include "pch.h"
#include "ChildWindow.h"

using namespace std;

namespace gui_framework
{
	LRESULT ChildWindow::preWindowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed)
	{
		return BaseResizableComposite::preWindowMessagesHandle(handle, message, wparam, lparam, isUsed);
	}

	ChildWindow::ChildWindow(const wstring& className, const wstring& windowName, const utility::ComponentSettings& settings, BaseComponent* parent, const string& windowFunctionName) :
		BaseComposite
		(
			className,
			windowName,
			settings,
			parent,
			windowFunctionName
		),
		BaseResizableComposite
		(
			className,
			windowName,
			settings,
			parent,
			windowFunctionName
		),
		BaseChildWindow
		(
			className,
			windowName,
			settings,
			parent,
			windowFunctionName
		)
	{

	}
}
