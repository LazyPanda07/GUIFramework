#pragma once

#include "BaseComponents/StandardComponents/BaseListBox.h"

namespace gui_framework
{
	class ListBox : public BaseListBox
	{
	public:
		ListBox(const std::wstring& listBoxName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent, bool multipleSelect = false);

		~ListBox() = default;
	};
}
