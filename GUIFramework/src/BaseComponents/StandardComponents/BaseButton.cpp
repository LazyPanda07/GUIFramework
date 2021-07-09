#include "pch.h"
#include "BaseButton.h"

#include "Exceptions/GetLastErrorException.h"
#include "Exceptions/NotImplemented.h"

using namespace std;

namespace gui_framework
{
	BaseButton::BaseButton(const wstring& buttonName, const wstring& buttonText, const utility::ComponentSettings& settings, BaseComponent* parent, const function<LRESULT(WPARAM, LPARAM)>& onClick) :
		BaseComponent
		(
			wstring(standard_classes::button),
			buttonName,
			settings,
			parent
		),
		ITextOperations(handle),
		onClick(onClick)
	{
		this->setText(buttonText);
	}

	void BaseButton::setOnClick(const function<LRESULT(WPARAM, LPARAM)>& onClick)
	{
		this->onClick = onClick;
	}

	const function<LRESULT(WPARAM, LPARAM)>& BaseButton::getOnClick() const
	{
		return onClick;
	}

	LRESULT BaseButton::windowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed)
	{
		if (message == WM_COMMAND && id == LOWORD(wparam))
		{
			isUsed = true;

			if (onClick)
			{
				return onClick(wparam, lparam);
			}
		}

		isUsed = false;

		return -1;
	}

	void BaseButton::setTextColor(uint8_t red, uint8_t green, uint8_t blue)
	{
		throw exceptions::NotImplemented(__FUNCTION__, "BaseButton");
	}
}
