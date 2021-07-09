#pragma once

#include "BaseComponents/StandardComponents/BaseCheckBox.h"
#include "BaseComponents/BaseResizableComponent.h"

#pragma warning(push)
#pragma warning(disable: 4250)

namespace gui_framework
{
	/// @brief Standard check box
	class GUI_FRAMEWORK_API CheckBox : public BaseCheckBox
	{
	public:
		CheckBox(const std::wstring& checkBoxName, const std::wstring& checkBoxText, int x, int y, BaseComponent* parent, const std::function<LRESULT(WPARAM, LPARAM)>& onCheck, const std::function<LRESULT(WPARAM, LPARAM)>& onClear, const std::function<LRESULT(WPARAM, LPARAM)>& onClick = nullptr, uint16_t width = standard_sizes::checkBoxWidth, uint16_t height = standard_sizes::checkBoxHeight);

		~CheckBox() = default;
	};
}

#pragma warning(pop)
