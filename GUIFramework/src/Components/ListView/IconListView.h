#pragma once

#include "BaseComponents/StandardComponents/ListView/BaseIconListView.h"

namespace gui_framework
{
	class GUI_FRAMEWORK_API IconListView : public BaseIconListView
	{
	public:
		IconListView(const std::wstring& listViewName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent, utility::iconListViewType type, uint16_t iconsWidth);

		~IconListView() = default;
	};
}
