#pragma once

#include "BaseComponents/StandardComponents/ListView/BaseListTextIconListView.h"

namespace gui_framework
{
	class ListTextIconListView : public BaseListTextIconListView
	{
	public:
		ListTextIconListView(const std::wstring& listViewName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent, utility::iconListViewType type);

		~ListTextIconListView() = default;
	};
}
