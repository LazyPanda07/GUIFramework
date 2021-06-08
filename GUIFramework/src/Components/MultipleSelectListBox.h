#pragma once

#include "BaseComponents/StandardComponents/BaseMultipleSelectListBox.h"

namespace gui_framework
{
	class MultipleSelectListBox : public BaseMultipleSelectListBox
	{
	public:
		MultipleSelectListBox(const std::wstring& listBoxName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent, bool isSorting = false);

		~MultipleSelectListBox() = default;
	};
}
