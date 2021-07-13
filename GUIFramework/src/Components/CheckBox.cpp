#include "pch.h"
#include "CheckBox.h"

using namespace std;

namespace gui_framework
{
	CheckBox::CheckBox(const wstring& checkBoxName, const wstring& checkBoxText, int x, int y, BaseComponent* parent, const function<void()>& onCheck, const function<void()>& onClear, const function<void()>& onClick, uint16_t width, uint16_t height) :
		BaseCheckBox
		(
			checkBoxName,
			checkBoxText,
			utility::ComponentSettings
			(
				NULL,
				x,
				y,
				width,
				height
			),
			parent,
			onCheck,
			onClear,
			onClick
		)
	{

	}
}
