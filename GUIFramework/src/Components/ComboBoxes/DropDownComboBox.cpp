#include "headers.h"
#include "DropDownComboBox.h"

#include "Styles/Components/ComboBoxes/DropDownComboBoxStyles.h"

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

	json::JSONBuilder DropDownComboBox::getStructure() const
	{
		using json::utility::jsonObject;
		using json::utility::objectSmartPointer;

		json::JSONBuilder builder = BaseComboBox::getStructure();
		objectSmartPointer<jsonObject>& current = get<objectSmartPointer<jsonObject>>(builder[utility::to_string(windowName, ISerializable::getCodepage())]);

		__utility::changeClassName(current, serialized_classes::dropDownComboBox);

		return builder;
	}
}
