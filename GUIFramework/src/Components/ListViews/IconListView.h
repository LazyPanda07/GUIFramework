#pragma once

#include "BaseComponents/StandardComponents/ListViews/BaseIconListView.h"

namespace gui_framework
{
	/// @brief Standard list view with icon items
	class GUI_FRAMEWORK_API IconListView : public BaseIconListView
	{
	public:
		IconListView(const std::wstring& listViewName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent, utility::iconListViewType type);

		~IconListView() = default;
	};
}
