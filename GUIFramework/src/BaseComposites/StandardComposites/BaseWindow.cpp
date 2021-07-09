#include "pch.h"
#include "BaseWindow.h"

using namespace std;

namespace gui_framework
{
	BaseWindow::BaseWindow(const std::wstring& className, const std::wstring& windowName, const utility::ComponentSettings& settings, BaseComponent* parent, const string& windowFunctionName) :
		BaseComposite
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
