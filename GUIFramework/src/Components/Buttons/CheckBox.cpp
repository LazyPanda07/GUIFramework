#include "headers.h"
#include "CheckBox.h"

using namespace std;

namespace gui_framework
{
	CheckBox::CheckBox(const wstring& checkBoxName, const wstring& checkBoxText, int x, int y, BaseComponent* parent, const function<void()>& onCheck, const function<void()>& onClear, const function<void()>& onClick, uint16_t width, uint16_t height) :
		BaseCheckBox
		(
			checkBoxName,
			checkBoxText,
			utility::ComponentSettings
			(
				x,
				y,
				width,
				height
			),
			parent,
			onCheck,
			onClear,
			onClick
		)
	{

	}

	json::JSONBuilder CheckBox::getStructure() const
	{
		using json::utility::jsonObject;
		using json::utility::objectSmartPointer;

		json::JSONBuilder builder = BaseCheckBox::getStructure();
		objectSmartPointer<jsonObject>& current = get<objectSmartPointer<jsonObject>>(builder[utility::to_string(windowName, ISerializable::getCodepage())]);

		__utility::changeClassName(current, serialized_classes::checkBox);

		return builder;
	}
}
