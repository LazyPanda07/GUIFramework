#include "pch.h"
#include "BaseListIconListView.h"

using namespace std;

namespace gui_framework
{
	BaseListIconListView::BaseListIconListView(const wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent, utility::iconListViewType type, uint16_t iconsWidth, uint16_t iconsHeight, size_t count) :
		BaseComponent
		(
			wstring(standard_classes::listView),
			listViewName,
			utility::ComponentSettings
			(
				settings.styles | LVS_LIST | static_cast<uint32_t>(type),
				settings.x,
				settings.y,
				settings.width,
				settings.height,
				settings.extendedStyles
			),
			parent
		),
		BaseListListView
		(
			listViewName,
			utility::ComponentSettings
			(
				settings.styles | static_cast<uint32_t>(type),
				settings.x,
				settings.y,
				settings.width,
				settings.height,
				settings.extendedStyles
			),
			parent
		),
		IIconListView(handle, images),
		images(iconsWidth, iconsHeight, count)
	{

	}
}
