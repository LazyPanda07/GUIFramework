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
		ITextOperations(handle),
		buttonId(buttonId),
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

	uint32_t BaseButton::getButtonId() const
	{
		return buttonId;
	}
}
