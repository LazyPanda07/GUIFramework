#include "pch.h"
#include "SimpleComboBox.h"

#include "Styles/Components/ComboBoxes/SimpleComboBoxStyles.h"

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

	json::JSONBuilder SimpleComboBox::getStructure() const
	{
		using json::utility::jsonObject;
		using json::utility::objectSmartPointer;

		json::JSONBuilder builder = BaseComponent::getStructure();
		objectSmartPointer<jsonObject>& current = get<objectSmartPointer<jsonObject>>(builder[utility::to_string(windowName, ISerializable::getCodepage())]);

		__utility::changeClassName(current, "SimpleComboBox");

		return builder;
	}
}
