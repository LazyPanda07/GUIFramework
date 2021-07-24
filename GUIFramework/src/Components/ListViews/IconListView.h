#pragma once

#include "pch.h"
#include "BaseComponents/StandardComponents/ListViews/BaseIconListView.h"

namespace gui_framework
{
	/// @brief Standard list view with icon items
	class GUI_FRAMEWORK_API IconListView : public BaseIconListView
	{
	public:
		IconListView(const std::wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent, utility::iconListViewType type);

		~IconListView() = default;
	};
}
