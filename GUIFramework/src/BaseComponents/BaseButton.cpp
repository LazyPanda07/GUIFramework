#include "pch.h"
#include "BaseButton.h"

#include "Exceptions/GetLastErrorException.h"

using namespace std;

namespace gui_framework
{
	BaseButton::BaseButton(const wstring& buttonName, const wstring& buttonText, const utility::ComponentSettings& settings, BaseComponent* parent, uint32_t buttonId, const function<LRESULT(WPARAM, LPARAM)>& onClick) :
		BaseComponent
		(
			wstring(standard_classes::button),
			buttonName,
			settings,
			parent
		),
		buttonId(buttonId),
		onClick(onClick)
	{
		this->setText(buttonText);
	}

	void BaseButton::setOnClick(const function<LRESULT(WPARAM, LPARAM)>& onClick)
	{
		this->onClick = onClick;
	}

	void BaseButton::setText(const wstring& buttonText) const
	{
		SetWindowTextW(handle, buttonText.data());
	}

	const function<LRESULT(WPARAM, LPARAM)>& BaseButton::getOnClick() const
	{
		return onClick;
	}

	uint32_t BaseButton::getButtonId() const
	{
		return buttonId;
	}

	wstring BaseButton::getText() const
	{
		int textLength = GetWindowTextLengthW(handle);
		wstring text;

		if (!textLength)
		{
			DWORD errorCode = GetLastError();

			if (!errorCode)
			{
				throw exceptions::GetLastErrorException(errorCode);
			}
		}

		text.resize(++textLength);

		GetWindowTextW(handle, text.data(), textLength);

		return text;
	}
}
