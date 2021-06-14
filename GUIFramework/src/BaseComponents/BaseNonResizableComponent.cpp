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
		),
		IResizableComponent
		(
			handle,
			parent ? parent->getHandle() : nullptr,
			false,
			true
		)
	{
		utility::removeStyle(handle, WS_THICKFRAME);
	}

	void BaseNonResizableComponent::resize(uint16_t width, uint16_t height)
	{

	}
}
