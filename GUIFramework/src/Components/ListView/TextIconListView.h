#pragma once

#include "BaseComponents/StandardComponents/ListView/BaseTextIconListView.h"

namespace gui_framework
{
	class TextIconListView : public BaseTextIconListView
	{
	public:
		TextIconListView(const std::wstring& listViewName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent, utility::iconListViewType type);

		~TextIconListView() = default;
	};
}
