#pragma once

#include "BaseComponents/StandardComponents/ListViews/BaseListIconListView.h"

namespace gui_framework
{
	/// @brief Standard list view in list mode with icon items
	class GUI_FRAMEWORK_API ListIconListView : public BaseListIconListView
	{
	public:
		ListIconListView(const std::wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent, utility::iconListViewType type);

		~ListIconListView() = default;
	};
}
