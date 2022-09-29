#pragma once

#include "core.h"
#include "BaseComponents/StandardComponents/ListBoxes/BaseMultipleSelectListBox.h"

namespace gui_framework
{
	/// @brief Standard multiple select list box
	class GUI_FRAMEWORK_API MultipleSelectListBox : public BaseMultipleSelectListBox
	{
	public:
		MultipleSelectListBox(const std::wstring& listBoxName, const utility::ComponentSettings& settings, BaseComponent* parent, bool isSorting = false);

		size_t getHash() const override;

		json::JSONBuilder getStructure() const override;

		~MultipleSelectListBox() = default;
	};
}
