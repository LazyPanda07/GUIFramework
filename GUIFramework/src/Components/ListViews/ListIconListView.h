#pragma once

#include "BaseComponents/StandardComponents/ListViews/BaseListIconListView.h"

namespace gui_framework
{
	/// @brief Standard list view in list mode with icon items
	class GUI_FRAMEWORK_API ListIconListView : public BaseListIconListView
	{
	public:
		ListIconListView(const std::wstring& listViewName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent, utility::iconListViewType type);

		~ListIconListView() = default;
	};
}