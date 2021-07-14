#include "pch.h"
#include "BaseTextIconListView.h"

#include "Styles/Components/ListViews/IconListViewStyles.h"

using namespace std;

namespace gui_framework
{
	BaseTextIconListView::BaseTextIconListView(const wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent, utility::iconListViewType type, uint16_t iconsWidth, uint16_t iconsHeight, size_t count) :
		BaseListView
		(
			listViewName,
			settings,
			styles::IconListViewStyles(type),
			parent
		),
		ITextIconListView(handle, icons),
		icons(iconsWidth, iconsHeight, count)
	{
		SendMessageW(handle, LVM_SETIMAGELIST, type == utility::iconListViewType::icon ? LVSIL_NORMAL : LVSIL_SMALL, reinterpret_cast<LPARAM>(icons.getImageList()));
	}
}
