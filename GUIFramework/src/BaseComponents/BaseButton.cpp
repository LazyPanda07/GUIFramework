#include "pch.h"
#include "BaseButton.h"

using namespace std;

namespace gui_framework
{
	BaseButton::BaseButton(const wstring& buttonName, const utility::ComponentSettings& settings, BaseComponent* parent, uint32_t buttonId, const function<LRESULT(WPARAM, LPARAM)>& onClick) :
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
		
	}

	void BaseButton::setOnClick(const function<LRESULT(WPARAM, LPARAM)>& onClick)
	{
		this->onClick = onClick;
	}

	const function<LRESULT(WPARAM, LPARAM)>& BaseButton::getOnClick() const
	{
		return onClick;
	}
}
