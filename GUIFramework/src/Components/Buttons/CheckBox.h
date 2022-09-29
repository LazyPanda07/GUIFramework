#pragma once

#include "core.h"
#include "BaseComponents/StandardComponents/Buttons/BaseCheckBox.h"

namespace gui_framework
{
	/// @brief Standard check box
	class GUI_FRAMEWORK_API CheckBox : public BaseCheckBox
	{
	public:
		CheckBox(const std::wstring& checkBoxName, const std::wstring& checkBoxText, const utility::ComponentSettings& settings, BaseComposite* parent, const std::function<void()>& onCheck, const std::function<void()>& onClear, const std::function<void()>& onClick = nullptr);

		size_t getHash() const override;

		json::JSONBuilder getStructure() const override;

		~CheckBox() = default;
	};
}
