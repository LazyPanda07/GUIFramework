#include "headers.h"
#include "ChildWindow.h"

using namespace std;

namespace gui_framework
{
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

	size_t ChildWindow::getHash() const
	{
		return typeid(ChildWindow).hash_code();
	}
}
