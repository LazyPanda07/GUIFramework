#pragma once

#include "BaseComponents/StandardComponents/ListViews/BaseListTextListView.h"

namespace gui_framework
{
	/// @brief Standard list view in list mode with text items
	class GUI_FRAMEWORK_API ListTextListView : public BaseListTextListView
	{
	public:
		ListTextListView(const std::wstring& listViewName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent);

		~ListTextListView() = default;
	};
}
