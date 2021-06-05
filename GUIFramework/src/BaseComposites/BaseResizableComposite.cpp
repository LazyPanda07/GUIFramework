#include "pch.h"
#include "BaseResizableComposite.h"

using namespace std;

namespace gui_framework
{
	BaseResizableComposite::BaseResizableComposite(const wstring& className, const wstring& windowName, const utility::ComponentSettings& settings, BaseComponent* parent, const string& windowFunctionName) :
		BaseComposite
		(
			className,
			windowName,
			utility::ComponentSettings
			(
				settings.styles | WS_THICKFRAME,
				settings.x,
				settings.y,
				settings.width,
				settings.height,
				settings.id,
				settings.extendedStyles
			),
			parent,
			windowFunctionName
		),
		IResizableComponent
		(
			handle,
			parent ? parent->getHandle() : GetDesktopWindow()
		)
	{

	}

	void BaseResizableComposite::resize(uint16_t width, uint16_t height)
	{

	}
}
