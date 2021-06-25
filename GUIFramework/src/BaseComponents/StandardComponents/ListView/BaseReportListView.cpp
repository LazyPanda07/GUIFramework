#include "pch.h"
#include "BaseReportListView.h"

using namespace std;

namespace gui_framework
{
	BaseReportListView::BaseReportListView(const wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent) :
		BaseComponent
		(
			wstring(standard_classes::listView),
			listViewName,
			utility::ComponentSettings
			(
				settings.styles | LVS_REPORT,
				settings.x,
				settings.y,
				settings.width,
				settings.height,
				settings.extendedStyles
			),
			parent
		),
		BaseListView
		(
			listViewName,
			utility::ComponentSettings
			(
				settings.styles | LVS_REPORT,
				settings.x,
				settings.y,
				settings.width,
				settings.height,
				settings.extendedStyles
			),
			parent
		)
	{

	}
}
