#include "core.h"
#include "CheckBox.h"

using namespace std;

namespace gui_framework
{
	CheckBox::CheckBox(const wstring& checkBoxName, const wstring& checkBoxText, const utility::ComponentSettings& settings, BaseComponent* parent, const function<void()>& onCheck, const function<void()>& onClear, const function<void()>& onClick) :
		BaseCheckBox
		(
			checkBoxName,
			checkBoxText,
			settings,
			parent,
			onCheck,
			onClear,
			onClick
		)
	{

	}

	size_t CheckBox::getHash() const
	{
		return typeid(CheckBox).hash_code();
	}

	json::JSONBuilder CheckBox::getStructure() const
	{
		using json::utility::jsonObject;

		json::JSONBuilder builder = BaseCheckBox::getStructure();
		jsonObject& current = get<jsonObject>(builder[utility::to_string(windowName, ISerializable::getCodepage())]);

		return builder;
	}
}
