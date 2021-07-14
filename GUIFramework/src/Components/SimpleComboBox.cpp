#include "pch.h"
#include "SimpleComboBox.h"

#include "Styles/Components/SimpleComboBoxStyles.h"

using namespace std;

namespace gui_framework
{
	SimpleComboBox::SimpleComboBox(const wstring& comboBoxName, const utility::ComponentSettings& settings, BaseComponent* parent) :
		BaseComboBox
		(
			comboBoxName,
			settings,
			styles::SimpleComboBoxStyles(),
			parent
		)
	{

	}
}
