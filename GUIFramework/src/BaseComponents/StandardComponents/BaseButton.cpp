#include "pch.h"
#include "BaseButton.h"

#include "Exceptions/GetLastErrorException.h"

using namespace std;

namespace gui_framework
{
	HMENU BaseButton::initButtonId(uint32_t buttonId)
	{
		this->buttonId = buttonId;

		return HMENU(buttonId);
	}

	BaseButton::BaseButton(const wstring& buttonName, const wstring& buttonText, const utility::ComponentSettings& settings, BaseComponent* parent, const function<LRESULT(WPARAM, LPARAM)>& onClick) :
		BaseComponent
		(
			wstring(standard_classes::button),
			buttonName,
			utility::ComponentSettings
			(
				settings.styles,
				settings.x,
				settings.y,
				settings.width,
				settings.height,
				this->initButtonId(GUIFramework::get().generateHMENU(buttonName)),
				settings.extendedStyles
			),
			parent
		),
		ITextOperations(handle),
		onClick(onClick)
	{
		this->setText(buttonText);
	}

	LRESULT BaseButton::windowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed)
	{
		if (message == WM_COMMAND && buttonId == LOWORD(wparam))
		{
			isUsed = true;

			return onClick(wparam, lparam);
		}

		isUsed = false;

		return -1;
	}

	void BaseButton::setOnClick(const function<LRESULT(WPARAM, LPARAM)>& onClick)
	{
		this->onClick = onClick;
	}

	const function<LRESULT(WPARAM, LPARAM)>& BaseButton::getOnClick() const
	{
		return onClick;
	}

	uint32_t BaseButton::getButtonId() const
	{
		return buttonId;
	}
}
