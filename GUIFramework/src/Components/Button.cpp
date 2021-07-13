#include "pch.h"
#include "Button.h"

using namespace std;

namespace gui_framework
{
	Button::Button(const wstring& buttonName, const wstring& buttonText, int x, int y, BaseComponent* parent, const function<void()>& onClick, uint16_t width, uint16_t height) :
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
		),
		IResizableComponent
		(
			handle,
			parent->getHandle()
		)	
	{

	}
}
