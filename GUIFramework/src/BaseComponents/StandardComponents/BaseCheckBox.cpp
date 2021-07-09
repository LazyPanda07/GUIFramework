#include "pch.h"
#include "BaseCheckBox.h"

using namespace std;

namespace gui_framework
{
	BaseCheckBox::BaseCheckBox(const wstring& checkBoxName, const wstring& checkBoxText, const utility::ComponentSettings& settings, BaseComponent* parent, const function<LRESULT(WPARAM, LPARAM)>& onCheck, const function<LRESULT(WPARAM, LPARAM)>& onClear, const function<LRESULT(WPARAM, LPARAM)>& onClick) :
		BaseComponent
		(
			wstring(standard_classes::button),
			checkBoxName,
			utility::ComponentSettings
			(
				settings.styles | BS_CHECKBOX,
				settings.x,
				settings.y,
				settings.width,
				settings.height,
				settings.extendedStyles
			),
			parent
		),
		BaseButton
		(
			checkBoxName,
			checkBoxText,
			utility::ComponentSettings
			(
				settings.styles | BS_CHECKBOX,
				settings.x,
				settings.y,
				settings.width,
				settings.height,
				settings.extendedStyles
			),
			parent,
			onClick
		),
		onCheck(onCheck),
		onClear(onClear)
	{

	}

	void BaseCheckBox::setOnCheck(const function<LRESULT(WPARAM, LPARAM)>& onCheck)
	{
		this->onCheck = onCheck;
	}

	void BaseCheckBox::setOnClear(const function<LRESULT(WPARAM, LPARAM)>& onClear)
	{
		this->onClear = onClear;
	}

	const function<LRESULT(WPARAM, LPARAM)>& BaseCheckBox::getOnCheck() const
	{
		return onCheck;
	}

	const function<LRESULT(WPARAM, LPARAM)>& BaseCheckBox::getOnClear() const
	{
		return onClear;
	}

	LRESULT BaseCheckBox::windowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed)
	{
		if (message == WM_COMMAND && id == LOWORD(wparam))
		{
			isUsed = true;

			LRESULT state = SendMessageW(this->handle, BM_GETCHECK, NULL, NULL);

			SendMessageW(this->handle, BM_SETCHECK, !state, NULL);

			if (onClear && state == BST_CHECKED)
			{
				return onClear(wparam, lparam);
			}
			else if (onCheck && state == BST_UNCHECKED)
			{
				return onCheck(wparam, lparam);
			}
			else if (onClick)
			{
				return onClick(wparam, lparam);
			}
		}

		isUsed = false;

		return -1;
	}
}
