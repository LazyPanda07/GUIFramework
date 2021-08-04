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
}
