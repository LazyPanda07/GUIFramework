#include "pch.h"
#include "RichEdit.h"

using namespace std;

namespace gui_framework
{
	RichEdit::RichEdit(const wstring& richEditName, const utility::ComponentSettings& settings, BaseComponent* parent, bool isMultiLine) :
		BaseRichEdit
		(
			richEditName,
			settings,
			parent,
			isMultiLine
		)
	{

	}

	json::JSONBuilder RichEdit::getStructure() const
	{
		using json::utility::objectSmartPointer;
		using json::utility::jsonObject;

		json::JSONBuilder builder = BaseRichEdit::getStructure();
		objectSmartPointer<jsonObject>& current = get<objectSmartPointer<jsonObject>>(builder[utility::to_string(windowName, ISerializable::getCodepage())]);

		__utility::changeClassName(current, serialized_classes::richEdit);

		return builder;
	}
}
