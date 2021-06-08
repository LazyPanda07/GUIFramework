#include "pch.h"
#include "ListBox.h"

using namespace std;

namespace gui_framework
{
	ListBox::ListBox(const wstring& listBoxName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent, bool isSorting) :
		BaseComponent
		(
			wstring(standard_classes::listBox),
			listBoxName,
			utility::ComponentSettings
			(
				WS_BORDER | (isSorting ? LBS_SORT : NULL),
				x,
				y,
				width,
				height
			),
			parent
		),
		BaseListBox
		(
			listBoxName,
			utility::ComponentSettings
			(
				WS_BORDER | (isSorting ? LBS_SORT : NULL),
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
