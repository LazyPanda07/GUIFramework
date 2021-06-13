#include "pch.h"
#include "Button.h"

using namespace std;

namespace gui_framework
{
	LRESULT Button::preWindowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed) 
	{
		return BaseResizableComponent::preWindowMessagesHandle(handle, message, wparam, lparam, isUsed);
	}

	Button::Button(const wstring& buttonName, const wstring& buttonText, int x, int y, BaseComponent* parent, const function<LRESULT(WPARAM, LPARAM)>& onClick, uint16_t width, uint16_t height) :
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
				height
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
				height
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
				height
			),
			parent,
			onClick
		)
	{

	}

	LRESULT Button::windowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed)
	{
		if (message == WM_COMMAND && buttonId == wparam)
		{
			isUsed = true;

			return onClick(wparam, lparam);
		}

		isUsed = false;

		return -1;
	}
}
