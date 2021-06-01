#include "pch.h"
#include "BaseChildWindow.h"

using namespace std;

namespace gui_framework
{
	BaseChildWindow::BaseChildWindow(const wstring& className, const wstring& windowName, const utility::ComponentSettings& settings, BaseComponent* parent, const string& windowFunctionName) :
		BaseWindow
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
