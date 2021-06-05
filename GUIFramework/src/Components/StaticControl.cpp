#include "pch.h"
#include "StaticControl.h"

using namespace std;

namespace gui_framework
{
	LRESULT StaticControl::preWindowMessagesHandle(HWND handle, UINT msg, WPARAM wparam, LPARAM lparam, bool& isUsed)
	{
		return BaseResizableComponent::preWindowMessagesHandle(handle, msg, wparam, lparam, isUsed);
	}

	StaticControl::StaticControl(const wstring& staticControlName, const wstring& editControlText, int x, int y, BaseComponent* parent, int width, int height) :
		BaseComponent
		(
			wstring(standard_classes::button),
			staticControlName,
			utility::ComponentSettings
			(
				NULL,
				x,
				y,
				width,
				height
			),
			parent
		),
		BaseResizableComponent
		(
			wstring(standard_classes::staticControl),
			editControlText,
			utility::ComponentSettings
			(
				WS_BORDER,
				x,
				y,
				width,
				height
			),
			parent
		),
		BaseStaticControl
		(
			staticControlName,
			editControlText,
			utility::ComponentSettings
			(
				WS_BORDER,
				x,
				y,
				width,
				height
			),
			parent
		)
	{

	}
}
