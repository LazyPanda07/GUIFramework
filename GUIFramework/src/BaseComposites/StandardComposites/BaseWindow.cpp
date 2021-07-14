#include "pch.h"
#include "BaseWindow.h"

using namespace std;

namespace gui_framework
{
	BaseWindow::BaseWindow(const std::wstring& className, const std::wstring& windowName, const utility::ComponentSettings& settings, const interfaces::IStyles& styles, BaseComponent* parent, const string& windowFunctionName) :
		BaseComposite
		(
			className,
			windowName,
			settings,
			styles,
			parent,
			windowFunctionName
		)
	{

	}
}
