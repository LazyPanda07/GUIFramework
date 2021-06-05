#include "pch.h"
#include "Button.h"

using namespace std;

namespace gui_framework
{
	LRESULT Button::preWindowMessagesHandle(HWND handle, UINT msg, WPARAM wparam, LPARAM lparam, bool& isUsed) 
	{
		return BaseResizableComponent::preWindowMessagesHandle(handle, msg, wparam, lparam, isUsed);
	}

	Button::Button(const wstring& buttonName, const wstring& buttonText, int x, int y, BaseComponent* parent, uint64_t buttonId, const function<LRESULT(WPARAM, LPARAM)>& onClick, int width, int height) :
		BaseComponent
		(
			wstring(standard_classes::button),
			buttonName,
			utility::ComponentSettings
			(
				NULL,
				x,
				y,
				width,
				height,
				HMENU(buttonId)
			),
			parent
		),
		BaseResizableComponent
		(
			wstring(standard_classes::button),
			buttonName,
			utility::ComponentSettings
			(
				NULL,
				x,
				y,
				width,
				height,
				HMENU(buttonId)
			),
			parent
		),
		BaseButton
		(
			buttonName,
			buttonText,
			utility::ComponentSettings
			(
				NULL,
				x,
				y,
				width,
				height,
				HMENU(buttonId)
			),
			parent,
			buttonId,
			onClick
		)
	{

	}

	LRESULT Button::windowMessagesHandle(HWND handle, UINT msg, WPARAM wparam, LPARAM lparam, bool& isUsed)
	{
		if (msg == WM_COMMAND && buttonId == wparam)
		{
			isUsed = true;

			return onClick(wparam, lparam);
		}

		isUsed = false;

		return -1;
	}
}
