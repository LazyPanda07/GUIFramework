#include "pch.h"
#include "EditControl.h"

using namespace std;

namespace gui_framework
{
	LRESULT EditControl::preWindowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed)
	{
		return BaseResizableComponent::preWindowMessagesHandle(handle, message, wparam, lparam, isUsed);
	}

	EditControl::EditControl(const wstring& editControlName, int x, int y, BaseComponent* parent, int width, int height) :
		BaseComponent
		(
			wstring(standard_classes::editControl),
			editControlName,
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
		BaseResizableComponent
		(
			wstring(standard_classes::editControl),
			editControlName,
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
		BaseEditControl
		(
			editControlName,
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
