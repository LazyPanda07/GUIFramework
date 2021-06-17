#pragma once

#include "BaseComponents/StandardComponents/BaseComboBox.h"

namespace gui_framework
{
	/// @brief Standard drop down combo box
	class GUI_FRAMEWORK_API DropDownComboBox : public BaseComboBox
	{
	public:
		DropDownComboBox(const std::wstring& comboBoxName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent);

		~DropDownComboBox() = default;
	};
}
