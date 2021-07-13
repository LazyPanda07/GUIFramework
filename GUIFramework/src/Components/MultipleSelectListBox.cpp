#include "pch.h"
#include "MultipleSelectListBox.h"

using namespace std;

namespace gui_framework
{
	MultipleSelectListBox::MultipleSelectListBox(const wstring& listBoxName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent, bool isSorting) :
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
