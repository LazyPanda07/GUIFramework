#pragma once

#include "BaseComponents/StandardComponents/ListViews/BaseListTextIconListView.h"

namespace gui_framework
{
	/// @brief Standard list view in list mode with text and icon items
	class ListTextIconListView : public BaseListTextIconListView
	{
	public:
		ListTextIconListView(const std::wstring& listViewName, const utility::ComponentSettings& settings, BaseComposite* parent, utility::iconListViewType type);

		size_t getHash() const override;

		json::JSONBuilder getStructure() const override;

		~ListTextIconListView() = default;
	};
}
