#pragma once

#include "BaseComponents/StandardComponents/ListBoxes/BaseListBox.h"

namespace gui_framework
{
	/// @brief Standard list box
	class GUI_FRAMEWORK_API ListBox : public BaseListBox
	{
	public:
		ListBox(const std::wstring& listBoxName, const utility::ComponentSettings& settings, BaseComposite* parent, bool isSorting = false);

		size_t getHash() const override;

		~ListBox() = default;
	};
}
