#pragma once

#include "pch.h"
#include "BaseComponents/StandardComponents/BaseComboBox.h"

namespace gui_framework
{
	/// @brief Standard drop down list combo box
	class GUI_FRAMEWORK_API DropDownListComboBox : public BaseComboBox
	{
	public:
		DropDownListComboBox(const std::wstring& comboBoxName, const utility::ComponentSettings& settings, BaseComponent* parent);

		virtual json::JSONBuilder getStructure() const override;

		~DropDownListComboBox() = default;
	};
}
