#include "pch.h"
#include "ComboListBox.h"

using namespace std;

namespace gui_framework
{
	ComboListBox::ComboListBox(const wstring& listBoxName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent, bool multipleSelect) :
		BaseComponent
		(
			wstring(standard_classes::listBox),
			listBoxName,
			utility::ComponentSettings
			(
				LBS_COMBOBOX | (multipleSelect ? LBS_MULTIPLESEL : NULL),
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
				LBS_COMBOBOX | (multipleSelect ? LBS_MULTIPLESEL : NULL),
				x,
				y,
				width,
				height
			),
			parent
		)
	{

	}

	void ComboListBox::resize(uint16_t width, uint16_t height)
	{
		if (autoResize && !blockResize)
		{

		}
	}
}
