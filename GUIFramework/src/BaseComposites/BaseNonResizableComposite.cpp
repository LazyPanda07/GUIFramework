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
			settings,
			parent,
			windowFunctionName
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

		utility::removeStyle(handle, WS_MAXIMIZEBOX);
	}

	void BaseNonResizableComposite::resize(uint16_t width, uint16_t height)
	{

	}
}
