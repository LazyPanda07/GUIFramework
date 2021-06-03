#include "pch.h"
#include "StandardButton.h"

using namespace std;

namespace gui_framework
{
	StandardButton::StandardButton(const wstring& buttonName, int x, int y, BaseComponent* parent, uint32_t buttonId, int width, int height, const function<LRESULT(WPARAM, LPARAM)>& onClick) :
		BaseButton
		(
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
			parent,
			buttonId,
			onClick
		)
	{

	}

	LRESULT StandardButton::windowMessagesHandle(HWND handle, UINT msg, WPARAM wparam, LPARAM lparam, bool& isUsed)
	{
		if ((msg == WM_COMMAND || msg == WM_NOTIFY) && buttonId == wparam)
		{
			isUsed = true;

			return onClick(wparam, lparam);
		}

		isUsed = false;
		
		return -1;
	}
}
