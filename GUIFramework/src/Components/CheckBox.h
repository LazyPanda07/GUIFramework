#pragma once

#include "BaseComponents/StandardComponents/BaseCheckBox.h"

namespace gui_framework
{
	/// @brief Standard check box
	class GUI_FRAMEWORK_API CheckBox : public BaseCheckBox
	{
	public:
		CheckBox(const std::wstring& checkBoxName, const std::wstring& checkBoxText, int x, int y, BaseComponent* parent, const std::function<void()>& onCheck, const std::function<void()>& onClear, const std::function<void()>& onClick = nullptr, uint16_t width = standard_sizes::checkBoxWidth, uint16_t height = standard_sizes::checkBoxHeight);

		~CheckBox() = default;
	};
}
