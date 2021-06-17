#pragma once

#include "BaseComponents/StandardComponents/BaseComboBox.h"

namespace gui_framework
{
	/// @brief Standard simple combo box
	class GUI_FRAMEWORK_API SimpleComboBox : public BaseComboBox
	{
	public:
		SimpleComboBox(const std::wstring& comboBoxName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent);

		~SimpleComboBox() = default;
	};
}
