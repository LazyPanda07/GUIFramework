#include "pch.h"
#include "DropDownComboBox.h"

using namespace std;

namespace gui_framework
{
	DropDownComboBox::DropDownComboBox(const wstring& comboBoxName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent) :
		BaseComboBox
		(
			comboBoxName,
			utility::ComponentSettings
			(
				CBS_DROPDOWN,
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
