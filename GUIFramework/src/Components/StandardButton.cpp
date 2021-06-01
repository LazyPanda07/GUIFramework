#include "pch.h"
#include "StandardButton.h"

using namespace std;

namespace gui_framework
{
	StandardButton::StandardButton(const wstring& buttonName, const utility::ComponentSettings& settings, BaseComponent* parent, uint32_t buttonId, const function<LRESULT(WPARAM, LPARAM)>& onClick) :
		BaseButton
		(
			buttonName,
			settings,
			parent,
			buttonId,
			onClick
		)
	{

	}

	LRESULT StandardButton::windowMessagesHandle(HWND handle, UINT msg, WPARAM wparam, LPARAM lparam, bool& isUsed)
	{
		if (msg == buttonId)
		{
			isUsed = true;

			return onClick(wparam, lparam);
		}

		isUsed = false;
		
		return -1;
	}
}
