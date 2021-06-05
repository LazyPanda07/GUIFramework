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
		SetWindowLongPtrW	// disable resize
		(
			handle,
			GWL_STYLE,
			GetWindowLongPtrW(handle,GWL_STYLE) ^ WS_THICKFRAME
		);
	}
}
