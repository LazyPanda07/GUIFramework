#include "headers.h"
#include "SeparateWindow.h"

using namespace std;

namespace gui_framework
{
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

	size_t SeparateWindow::getHash() const
	{
		return typeid(SeparateWindow).hash_code();
	}
}
