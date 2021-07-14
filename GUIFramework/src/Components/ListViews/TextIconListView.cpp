#include "pch.h"
#include "TextIconListView.h"

using namespace std;

namespace gui_framework
{
	TextIconListView::TextIconListView(const wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent, utility::iconListViewType type) :
		BaseTextIconListView
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
