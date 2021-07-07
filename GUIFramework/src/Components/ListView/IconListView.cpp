#include "pch.h"
#include "IconListView.h"

using namespace std;

namespace gui_framework
{
	IconListView::IconListView(const wstring& listViewName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent, utility::iconListViewType type, uint16_t iconsWidth) :
		BaseComponent
		(
			wstring(standard_classes::listView),
			listViewName,
			utility::ComponentSettings
			(
				static_cast<uint32_t>(type),
				x,
				y,
				width,
				height
			),
			parent
		),
		BaseIconListView
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
