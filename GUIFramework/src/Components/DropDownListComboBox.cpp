#include "pch.h"
#include "DropDownListComboBox.h"

#include "Styles/Components/DropDownListComboBoxStyles.h"

using namespace std;

namespace gui_framework
{
	DropDownListComboBox::DropDownListComboBox(const wstring& comboBoxName, const utility::ComponentSettings& settings, BaseComponent* parent) :
		BaseComboBox
		(
			comboBoxName,
			settings,
			styles::DropDownListComboBoxStyles(),
			parent
		)
	{

	}
}
