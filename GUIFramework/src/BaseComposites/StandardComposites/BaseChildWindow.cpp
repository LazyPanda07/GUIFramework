#include "BaseChildWindow.h"

#include "Styles/DefaultStyles.h"

using namespace std;

namespace gui_framework
{
	BaseChildWindow::BaseChildWindow(const wstring& className, const wstring& windowName, const utility::ComponentSettings& settings, BaseComposite* parent, const string& windowFunctionName) :
		BaseWindow
		(
			className,
			windowName,
			settings,
			styles::DefaultStyles(),
			parent,
			windowFunctionName
		)
	{

	}
}
