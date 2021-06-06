#pragma once

#include "BaseComponents/StandardComponents/BaseComboBox.h"

namespace gui_framework
{
	class ComboBox : public BaseComboBox
	{
	public:
		ComboBox(const std::wstring& comboBoxName, int x, int y, BaseComponent* parent, uint16_t width = standard_sizes::comboBoxWidth, uint16_t height = standard_sizes::comboBoxHeight);

		~ComboBox() = default;
	};
}
