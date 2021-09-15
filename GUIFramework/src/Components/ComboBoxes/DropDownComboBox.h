#pragma once

#include "headers.h"
#include "BaseComponents/StandardComponents/BaseComboBox.h"

namespace gui_framework
{
	/// @brief Standard drop down combo box
	class GUI_FRAMEWORK_API DropDownComboBox : public BaseComboBox
	{
	public:
		DropDownComboBox(const std::wstring& comboBoxName, const utility::ComponentSettings& settings, BaseComponent* parent);

		size_t getHash() const override;

		json::JSONBuilder getStructure() const override;

		~DropDownComboBox() = default;
	};
}
