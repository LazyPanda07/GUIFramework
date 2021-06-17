#pragma once

#include "BaseComponents/StandardComponents/BaseComboBox.h"

namespace gui_framework
{
	/// @brief Standard drop down list combo box
	class GUI_FRAMEWORK_API DropDownListComboBox : public BaseComboBox
	{
	public:
		DropDownListComboBox(const std::wstring& comboBoxName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent);

		~DropDownListComboBox() = default;
	};
}
