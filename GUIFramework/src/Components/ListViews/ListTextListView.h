#pragma once

#include "BaseComponents/StandardComponents/ListViews/BaseListTextListView.h"

namespace gui_framework
{
	/// @brief Standard list view in list mode with text items
	class GUI_FRAMEWORK_API ListTextListView : public BaseListTextListView
	{
	public:
		ListTextListView(const std::wstring& listViewName, const utility::ComponentSettings& settings, BaseComposite* parent);

		size_t getHash() const override;

		json::JSONBuilder getStructure() const override;

		~ListTextListView() = default;
	};
}
