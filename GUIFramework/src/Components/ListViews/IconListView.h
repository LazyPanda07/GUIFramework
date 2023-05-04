#pragma once

#include "BaseComponents/StandardComponents/ListViews/BaseIconListView.h"

namespace gui_framework
{
	/// @brief Standard list view with icon items
	class GUI_FRAMEWORK_API IconListView : public BaseIconListView
	{
	public:
		IconListView(const std::wstring& listViewName, const utility::ComponentSettings& settings, BaseComposite* parent, utility::iconListViewType type);

		size_t getHash() const override;

		json::JSONBuilder getStructure() const override;

		~IconListView() = default;
	};
}
