#include "pch.h"
#include "BaseNonResizableComponent.h"

using namespace std;

namespace gui_framework
{
	BaseNonResizableComponent::BaseNonResizableComponent(const wstring& className, const wstring& windowName, const utility::ComponentSettings& settings, BaseComponent* parent, const string& windowFunctionName, const wstring& moduleName) :
		BaseComponent
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
			windowFunctionName,
			moduleName
		)
	{

	}
}
