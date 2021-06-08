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
			settings,
			parent,
			windowFunctionName,
			moduleName
		)
	{
		utility::removeStyle(handle, WS_THICKFRAME);
	}
}
