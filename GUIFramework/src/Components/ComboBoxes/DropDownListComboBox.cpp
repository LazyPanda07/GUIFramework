#include "core.h"
#include "DropDownListComboBox.h"

#include "Styles/Components/ComboBoxes/DropDownListComboBoxStyles.h"

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

	size_t DropDownListComboBox::getHash() const
	{
		return typeid(DropDownListComboBox).hash_code();
	}

	json::JSONBuilder DropDownListComboBox::getStructure() const
	{
		using json::utility::jsonObject;

		json::JSONBuilder builder = BaseComboBox::getStructure();
		jsonObject& current = get<jsonObject>(builder[utility::to_string(windowName, ISerializable::getCodepage())]);

		return builder;
	}
}
