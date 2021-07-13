#include "pch.h"
#include "ListTextIconListView.h"

using namespace std;

namespace gui_framework
{
	ListTextIconListView::ListTextIconListView(const wstring& listViewName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent, utility::iconListViewType type) :
		BaseListTextIconListView
		(
			listViewName,
			utility::ComponentSettings
			(
				static_cast<uint32_t>(type),
				x,
				y,
				width,
				height
			),
			parent,
			type,
			type == utility::iconListViewType::icon ? standard_sizes::largeIconWidth : standard_sizes::smallIconWidth,
			type == utility::iconListViewType::icon ? standard_sizes::largeIconHeight : standard_sizes::smallIconHeight
		)
	{
		
	}
}
