#include "pch.h"
#include "ListTextIconListView.h"

using namespace std;

namespace gui_framework
{
	ListTextIconListView::ListTextIconListView(const wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent, utility::iconListViewType type) :
		BaseListTextIconListView
		(
			listViewName,
			settings,
			parent,
			type,
			type == utility::iconListViewType::icon ? standard_sizes::largeIconWidth : standard_sizes::smallIconWidth,
			type == utility::iconListViewType::icon ? standard_sizes::largeIconHeight : standard_sizes::smallIconHeight
		)
	{
		
	}
}
