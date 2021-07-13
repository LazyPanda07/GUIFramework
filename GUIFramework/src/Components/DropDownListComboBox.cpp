#include "pch.h"
#include "DropDownListComboBox.h"

using namespace std;

namespace gui_framework
{
	DropDownListComboBox::DropDownListComboBox(const wstring& comboBoxName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent) :
		BaseComboBox
		(
			comboBoxName,
			utility::ComponentSettings
			(
				CBS_DROPDOWNLIST,
				x,
				y,
				width,
				height
			),
			parent
		)
	{

	}
}
