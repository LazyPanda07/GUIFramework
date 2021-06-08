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
		)
	{
		utility::removeStyle(handle, WS_THICKFRAME);
	}
}
