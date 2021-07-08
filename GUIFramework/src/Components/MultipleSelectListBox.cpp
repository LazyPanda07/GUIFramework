#include "pch.h"
#include "MultipleSelectListBox.h"

using namespace std;

namespace gui_framework
{
	MultipleSelectListBox::MultipleSelectListBox(const wstring& listBoxName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent, bool isSorting) :
		BaseComponent
		(
			wstring(standard_classes::listBox),
			listBoxName,
			utility::ComponentSettings
			(
				LBS_MULTIPLESEL | (isSorting ? LBS_SORT : NULL),
				x,
				y,
				width,
				height
			),
			parent
		),
		BaseMultipleSelectListBox
		(
			listBoxName,
			utility::ComponentSettings
			(
				(isSorting ? LBS_SORT : NULL),
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
