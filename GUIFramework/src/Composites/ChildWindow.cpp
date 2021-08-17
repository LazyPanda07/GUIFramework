#include "pch.h"
#include "ChildWindow.h"

using namespace std;

namespace gui_framework
{
	string ChildWindow::getCreationType() const
	{
		return "ChildWindow";
	}

	ChildWindow::ChildWindow(const wstring& className, const wstring& windowName, const utility::ComponentSettings& settings, BaseComponent* parent, const string& windowFunctionName) :
		BaseChildWindow
		(
			className,
			windowName,
			settings,
			parent,
			windowFunctionName
		),
		IResizableComponent
		(
			handle,
			parent->getHandle()
		)
	{

	}
}
