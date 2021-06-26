#include "pch.h"
#include "BaseReportTextIconListView.h"

using namespace std;

namespace gui_framework
{
	BaseReportTextIconListView::BaseReportTextIconListView(const wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent, utility::iconListViewType type, uint16_t iconsWidth, uint16_t iconsHeight, size_t count) :
		BaseComponent
		(
			wstring(standard_classes::listView),
			listViewName,
			utility::ComponentSettings
			(
				settings.styles | LVS_REPORT | static_cast<uint32_t>(type),
				settings.x,
				settings.y,
				settings.width,
				settings.height,
				settings.extendedStyles
			),
			parent
		),
		BaseReportListView
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
		ITextIconListView(handle, images),
		images(iconsWidth, iconsHeight, count)
	{

	}
}
