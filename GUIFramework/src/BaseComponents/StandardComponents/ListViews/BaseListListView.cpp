#include "pch.h"
#include "BaseListListView.h"

using namespace std;

namespace gui_framework
{
	BaseListListView::BaseListListView(const wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent) :
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
