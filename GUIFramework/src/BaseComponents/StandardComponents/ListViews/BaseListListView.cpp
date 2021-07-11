#include "pch.h"
#include "BaseListListView.h"

using namespace std;

namespace gui_framework
{
	BaseListListView::BaseListListView(const wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent) :
		BaseComponent
		(
			wstring(standard_classes::listView),
			listViewName,
			utility::ComponentSettings
			(
				settings.styles | LVS_LIST,
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
				settings.styles | LVS_LIST,
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
