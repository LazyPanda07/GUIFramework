#pragma once

#include "BaseComponents/StandardComponents/ListView/BaseListIconListView.h"

namespace gui_framework
{
	class GUI_FRAMEWORK_API ListIconListView : public BaseListIconListView
	{
	public:
		ListIconListView(const std::wstring& listViewName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent, utility::iconListViewType type);

		~ListIconListView() = default;
	};
}
