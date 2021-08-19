#include "pch.h"
#include "BaseSeparateWindow.h"

#include "Styles/Composites/SeparateWindowStyles.h"

using namespace std;

namespace gui_framework
{
	const string& BaseSeparateWindow::getCreationType() const
	{
		return serialized_creation_type::baseSeparateWindow;
	}

	BaseSeparateWindow::BaseSeparateWindow(const wstring& className, const wstring& titleName, const utility::ComponentSettings& settings, const string& windowFunctionName, bool maximize, bool minimize, const string& moduleName, uint16_t smallIconResource, uint16_t largeIconResource) :
		BaseWindow
		(
			className,
			titleName,
			settings,
			styles::SeparateWindowStyles(maximize, minimize),
			nullptr,
			windowFunctionName,
			moduleName,
			smallIconResource,
			largeIconResource
		)
	{
		
	}
}

