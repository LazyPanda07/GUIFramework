#include "pch.h"
#include "BaseCheckBox.h"

using namespace std;

namespace gui_framework
{
	LRESULT BaseCheckBox::windowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed)
	{
		if (message == WM_COMMAND && id == LOWORD(wparam))
		{
			isUsed = true;

			LRESULT state = SendMessageW(this->handle, BM_GETCHECK, NULL, NULL);

			SendMessageW(this->handle, BM_SETCHECK, !state, NULL);

			if (onClear && state == BST_CHECKED)
			{
				onClear();

				return 0;
			}
			else if (onCheck && state == BST_UNCHECKED)
			{
				onCheck();

				return 0;
			}
			else if (onClick)
			{
				onClick();

				return 0;
			}
		}

		isUsed = false;

		return -1;
	}

	BaseCheckBox::BaseCheckBox(const wstring& checkBoxName, const wstring& checkBoxText, const utility::ComponentSettings& settings, BaseComponent* parent, const function<void()>& onCheck, const function<void()>& onClear, const function<void()>& onClick) :
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

	void BaseCheckBox::setOnCheck(const function<void()>& onCheck)
	{
		this->onCheck = onCheck;
	}

	void BaseCheckBox::setOnClear(const function<void()>& onClear)
	{
		this->onClear = onClear;
	}

	const function<void()>& BaseCheckBox::getOnCheck() const
	{
		return onCheck;
	}

	const function<void()>& BaseCheckBox::getOnClear() const
	{
		return onClear;
	}
}
