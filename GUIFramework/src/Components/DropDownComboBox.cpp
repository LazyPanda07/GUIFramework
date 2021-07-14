#include "pch.h"
#include "DropDownComboBox.h"

#include "Styles/Components/DropDownComboBoxStyles.h"

using namespace std;

namespace gui_framework
{
	DropDownComboBox::DropDownComboBox(const wstring& comboBoxName, const utility::ComponentSettings& settings, BaseComponent* parent) :
		BaseComboBox
		(
			comboBoxName,
			settings,
			styles::DropDownComboBoxStyles(),
			parent
		)
	{

	}
}
