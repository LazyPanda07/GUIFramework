#include "headers.h"
#include "ChildWindow.h"

#include "Exceptions/NotImplemented.h"

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

	unique_ptr<Menu>& ChildWindow::createMainMenu(const wstring& menuName)
	{
		__utility::throwNotImplementedException(__FUNCTION__, "ChildWindow"sv);

		return BaseComposite::createMainMenu(menuName);
	}

	Menu& ChildWindow::addPopupMenu(const wstring& menuName)
	{
		__utility::throwNotImplementedException(__FUNCTION__, "ChildWindow"sv);

		return BaseComposite::addPopupMenu(menuName);
	}

	void ChildWindow::removePopupMenus(const wstring& menuName)
	{
		__utility::throwNotImplementedException(__FUNCTION__, "ChildWindow"sv);
	}

	size_t ChildWindow::getHash() const
	{
		return typeid(ChildWindow).hash_code();
	}
}
