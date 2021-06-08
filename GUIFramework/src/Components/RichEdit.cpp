#include "pch.h"
#include "RichEdit.h"

using namespace std;

namespace gui_framework
{
	RichEdit::RichEdit(const wstring& richEditName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent, bool isMultiLine) :
		BaseComponent
		(
			wstring(standard_classes::richEdit),
			windowName,
			utility::ComponentSettings
			(
				WS_BORDER | WS_VSCROLL | WS_HSCROLL | (isMultiLine ? ES_MULTILINE : NULL),
				x,
				y,
				width,
				height
			),
			parent
		),
		BaseRichEdit
		(
			richEditName,
			utility::ComponentSettings
			(
				WS_BORDER | WS_VSCROLL | WS_HSCROLL | (isMultiLine ? ES_MULTILINE : NULL),
				x,
				y,
				width,
				height
			),
			parent
		)
	{

	}
}
