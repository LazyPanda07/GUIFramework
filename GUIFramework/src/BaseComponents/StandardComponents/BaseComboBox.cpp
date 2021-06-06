#include "pch.h"
#include "BaseComboBox.h"

using namespace std;

namespace gui_framework
{
	BaseComboBox::BaseComboBox(const wstring& comboBoxName, const utility::ComponentSettings& settings, BaseComponent* parent) :
		BaseComponent
		(
			wstring(standard_classes::comboBox),
			comboBoxName,
			settings,
			parent
		)
	{

	}
}
