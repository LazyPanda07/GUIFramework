#include "pch.h"
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

	json::JSONBuilder DropDownListComboBox::getStructure() const
	{
		using json::utility::jsonObject;
		using json::utility::objectSmartPointer;

		json::JSONBuilder builder = BaseComponent::getStructure();
		objectSmartPointer<jsonObject>& current = get<objectSmartPointer<jsonObject>>(builder[utility::to_string(windowName, ISerializable::getCodepage())]);

		__utility::changeClassName(current, "DropDownListComboBox");

		return builder;
	}
}
