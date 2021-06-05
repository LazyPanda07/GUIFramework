#include "pch.h"
#include "SeparateWindow.h"

using namespace std;

namespace gui_framework
{
	LRESULT SeparateWindow::preWindowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed)
	{
		return BaseResizableComposite::preWindowMessagesHandle(handle, message, wparam, lparam, isUsed);
	}

	SeparateWindow::SeparateWindow(const std::wstring& className, const std::wstring& titleName, const utility::ComponentSettings& settings, const std::string& windowFunctionName) :
		BaseComposite
		(
			className,
			titleName,
			settings,
			nullptr,
			windowFunctionName
		),
		BaseResizableComposite
		(
			className,
			titleName,
			settings,
			nullptr,
			windowFunctionName
		),
		BaseSeparateWindow
		(
			className,
			titleName,
			settings,
			windowFunctionName
		)
	{

	}
}
