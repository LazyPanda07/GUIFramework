#include "pch.h"
#include "MultiColumnListBox.h"

using namespace std;

namespace gui_framework
{
	MultiColumnListBox::MultiColumnListBox(const wstring& listBoxName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent, bool multipleSelect) :
		BaseComponent
		(
			wstring(standard_classes::listBox),
			listBoxName,
			utility::ComponentSettings
			(
				LBS_MULTICOLUMN | (multipleSelect ? LBS_MULTIPLESEL : NULL),
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
				LBS_MULTICOLUMN | (multipleSelect ? LBS_MULTIPLESEL : NULL),
				x,
				y,
				width,
				height
			),
			parent
		)
	{

	}

	void MultiColumnListBox::resize(uint16_t width, uint16_t height)
	{
		if (autoResize && !blockResize)
		{

		}
	}
}
