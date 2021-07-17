#pragma once

#include "BaseComponents/StandardComponents/BaseMultipleSelectListBox.h"

namespace gui_framework
{
	/// @brief Standard multiple select list box
	class GUI_FRAMEWORK_API MultipleSelectListBox : public BaseMultipleSelectListBox
	{
	public:
		MultipleSelectListBox(const std::wstring& listBoxName, const utility::ComponentSettings& settings, BaseComponent* parent, bool isSorting = false);

		~MultipleSelectListBox() = default;
	};
}
