#pragma once

#include "pch.h"
#include "BaseComponents/StandardComponents/ListViews/BaseTextIconListView.h"

namespace gui_framework
{
	/// @brief Standard list view with text and icon items
	class TextIconListView : public BaseTextIconListView
	{
	public:
		TextIconListView(const std::wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent, utility::iconListViewType type);

		~TextIconListView() = default;
	};
}
