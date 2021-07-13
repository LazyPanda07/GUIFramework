#include "pch.h"
#include "BaseSeparateWindow.h"

using namespace std;

namespace gui_framework
{
	BaseSeparateWindow::BaseSeparateWindow(const wstring& className, const wstring& titleName, const utility::ComponentSettings& settings, const string& windowFunctionName) :
		BaseWindow
		(
			className,
			titleName,
			settings,
			nullptr,
			windowFunctionName
		)
	{
		
	}
}

