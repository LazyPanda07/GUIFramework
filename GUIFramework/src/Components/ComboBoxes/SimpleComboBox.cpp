#include "headers.h"
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

	size_t SimpleComboBox::getHash() const
	{
		return typeid(SimpleComboBox).hash_code();
	}

	json::JSONBuilder SimpleComboBox::getStructure() const
	{
		using json::utility::jsonObject;
		using json::utility::objectSmartPointer;

		json::JSONBuilder builder = BaseComboBox::getStructure();
		objectSmartPointer<jsonObject>& current = get<objectSmartPointer<jsonObject>>(builder[utility::to_string(windowName, ISerializable::getCodepage())]);

		return builder;
	}
}
