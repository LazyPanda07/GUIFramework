#include "pch.h"
#include "SeparateWindow.h"

using namespace std;

namespace gui_framework
{
	const string& SeparateWindow::getCreationType() const
	{
		return serialized_creation_type::separateWindow;
	}

	SeparateWindow::SeparateWindow(const std::wstring& className, const std::wstring& titleName, const utility::ComponentSettings& settings, const std::string& windowFunctionName, bool maximize, bool minimize) :
		BaseSeparateWindow
		(
			className,
			titleName,
			settings,
			windowFunctionName,
			maximize,
			minimize
		),
		IResizableComponent
		(
			handle,
			nullptr
		)	
	{

	}
}
