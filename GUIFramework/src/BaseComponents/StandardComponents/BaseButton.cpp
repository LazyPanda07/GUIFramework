#include "pch.h"
#include "BaseButton.h"

#include "Exceptions/GetLastErrorException.h"
#include "Exceptions/NotImplemented.h"

using namespace std;

namespace gui_framework
{
	LRESULT BaseButton::windowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed)
	{
		if (message == WM_COMMAND && id == LOWORD(wparam))
		{
			isUsed = true;

			if (onClick)
			{
				onClick();

				return 0;
			}
		}

		isUsed = false;

		return -1;
	}

	BaseButton::BaseButton(const wstring& buttonName, const wstring& buttonText, const utility::ComponentSettings& settings, BaseComponent* parent, const function<void()>& onClick) :
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

	void BaseButton::setOnClick(const function<void()>& onClick)
	{
		this->onClick = onClick;
	}

	const function<void()>& BaseButton::getOnClick() const
	{
		return onClick;
	}

	void BaseButton::setTextColor(uint8_t red, uint8_t green, uint8_t blue)
	{
		throw exceptions::NotImplemented(__FUNCTION__, "BaseButton");
	}
}
