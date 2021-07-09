#include "pch.h"
#include "CheckBox.h"

using namespace std;

namespace gui_framework
{
	CheckBox::CheckBox(const wstring& checkBoxName, const wstring& checkBoxText, int x, int y, BaseComponent* parent, const function<LRESULT(WPARAM, LPARAM)>& onCheck, const function<LRESULT(WPARAM, LPARAM)>& onClear, const function<LRESULT(WPARAM, LPARAM)>& onClick, uint16_t width, uint16_t height) :
		BaseComponent
		(
			wstring(standard_classes::button),
			checkBoxName,
			utility::ComponentSettings
			(
				BS_AUTOCHECKBOX,
				x,
				y,
				width,
				height
			),
			parent
		),
		BaseResizableComponent
		(
			wstring(standard_classes::button),
			checkBoxName,
			utility::ComponentSettings
			(
				BS_AUTOCHECKBOX,
				x,
				y,
				width,
				height
			),
			parent
		),
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
