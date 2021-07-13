#include "pch.h"
#include "SeparateWindow.h"

using namespace std;

namespace gui_framework
{
	SeparateWindow::SeparateWindow(const std::wstring& className, const std::wstring& titleName, const utility::ComponentSettings& settings, const std::string& windowFunctionName) :
		BaseSeparateWindow
		(
			className,
			titleName,
			settings,
			windowFunctionName
		),
		IResizableComponent
		(
			handle,
			nullptr
		)	
	{

	}
}
