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
		SetWindowLongPtrW	// disable resize
		(
			handle,
			GWL_STYLE,
			GetWindowLongPtrW(handle, GWL_STYLE) ^ WS_THICKFRAME
		);
	}
}
