#pragma once

#include "pch.h"
#include "BaseComponents/StandardComponents/BaseComboBox.h"

namespace gui_framework
{
	/// @brief Standard simple combo box
	class GUI_FRAMEWORK_API SimpleComboBox : public BaseComboBox
	{
	public:
		SimpleComboBox(const std::wstring& comboBoxName, const utility::ComponentSettings& settings, BaseComponent* parent);

		~SimpleComboBox() = default;
	};
}