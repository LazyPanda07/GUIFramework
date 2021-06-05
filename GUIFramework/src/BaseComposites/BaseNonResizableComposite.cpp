#include "pch.h"
#include "BaseNonResizableComposite.h"

using namespace std;

namespace gui_framework
{
	BaseNonResizableComposite::BaseNonResizableComposite(const wstring& className, const wstring& windowName, const utility::ComponentSettings& settings, BaseComponent* parent, const string& windowFunctionName) :
		BaseComposite
		(
			className,
			windowName,
			utility::ComponentSettings
			(
				settings.styles ^ WS_THICKFRAME,
				settings.x,
				settings.y,
				settings.width,
				settings.height,
				settings.id,
				settings.extendedStyles
			),
			parent,
			windowFunctionName
		)
	{

	}
}
