#pragma once

#include "headers.h"
#include "BaseComponents/StandardComponents/BaseListBox.h"

namespace gui_framework
{
	/// @brief Standard list box
	class GUI_FRAMEWORK_API ListBox : public BaseListBox
	{
	public:
		ListBox(const std::wstring& listBoxName, const utility::ComponentSettings& settings, BaseComponent* parent, bool isSorting = false);

		~ListBox() = default;
	};
}
