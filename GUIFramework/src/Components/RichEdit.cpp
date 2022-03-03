#include "headers.h"
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

	size_t RichEdit::getHash() const
	{
		return typeid(RichEdit).hash_code();
	}

	json::JSONBuilder RichEdit::getStructure() const
	{
		using json::utility::jsonObject;

		json::JSONBuilder builder = BaseRichEdit::getStructure();
		jsonObject& current = get<jsonObject>(builder[utility::to_string(windowName, ISerializable::getCodepage())]);

		return builder;
	}
}
