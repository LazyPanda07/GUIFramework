#include "pch.h"
#include "ComboBox.h"

using namespace std;

namespace gui_framework
{
	ComboBox::ComboBox(const wstring& comboBoxName, int x, int y, BaseComponent* parent, uint16_t width, uint16_t height) :
		BaseComponent
		(
			wstring(standard_classes::comboBox),
			comboBoxName,
			utility::ComponentSettings
			(
				NULL,
				x,
				y,
				width,
				height
			),
			parent
		),
		BaseComboBox
		(
			comboBoxName,
			utility::ComponentSettings
			(
				NULL,
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
