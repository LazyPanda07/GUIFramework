#include "pch.h"
#include "SimpleComboBox.h"

using namespace std;

namespace gui_framework
{
	SimpleComboBox::SimpleComboBox(const wstring& comboBoxName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent) :
		BaseComponent
		(
			wstring(standard_classes::comboBox),
			comboBoxName,
			utility::ComponentSettings
			(
				CBS_SIMPLE,
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
				CBS_SIMPLE,
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
