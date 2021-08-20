#include "pch.h"
#include "SeparateWindow.h"

using namespace std;

namespace gui_framework
{
	const string& SeparateWindow::getCreationType() const
	{
		return serialized_creation_type::separateWindow;
	}

	SeparateWindow::SeparateWindow(const std::wstring& className, const std::wstring& titleName, const utility::ComponentSettings& settings, const std::string& windowFunctionName, bool maximize, bool minimize, const string& moduleName, uint16_t smallIconResource, uint16_t largeIconResource) :
		BaseSeparateWindow
		(
			className,
			titleName,
			settings,
			windowFunctionName,
			maximize,
			minimize,
			moduleName,
			smallIconResource,
			largeIconResource
		),
		IResizableComponent
		(
			handle,
			nullptr
		)
	{

	}
}
