#pragma once

#include "BaseComponents/StandardComponents/ListViews/BaseTextListView.h"

namespace gui_framework
{
	/// @brief Standard list view with text items
	class GUI_FRAMEWORK_API TextListView : public BaseTextListView
	{
	public:
		TextListView(const std::wstring& listViewName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent);

		~TextListView() = default;
	};
}
