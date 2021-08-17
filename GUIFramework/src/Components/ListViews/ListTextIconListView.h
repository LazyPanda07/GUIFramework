#pragma once

#include "pch.h"
#include "BaseComponents/StandardComponents/ListViews/BaseListTextIconListView.h"

namespace gui_framework
{
	/// @brief Standard list view in list mode with text and icon items
	class ListTextIconListView : public BaseListTextIconListView
	{
	public:
		ListTextIconListView(const std::wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent, utility::iconListViewType type);

		json::JSONBuilder getStructure() const override;

		~ListTextIconListView() = default;
	};
}
