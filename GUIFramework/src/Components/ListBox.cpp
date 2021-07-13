#include "pch.h"
#include "ListBox.h"

using namespace std;

namespace gui_framework
{
	ListBox::ListBox(const wstring& listBoxName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent, bool isSorting) :
		BaseListBox
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
