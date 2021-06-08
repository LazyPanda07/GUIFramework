#pragma once

#include "BaseComponents/StandardComponents/BaseListBox.h"

namespace gui_framework
{
	class MultiColumnListBox : public BaseListBox
	{
	public:
		MultiColumnListBox(const std::wstring& listBoxName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent, bool multipleSelect = false);

		void resize(uint16_t width, uint16_t height) override;

		~MultiColumnListBox() = default;
	};
}
