#include "pch.h"
#include "BaseListTextListView.h"

using namespace std;

namespace gui_framework
{
	BaseListTextListView::BaseListTextListView(const wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent) :
		BaseListListView
		(
			listViewName,
			utility::ComponentSettings
			(
				settings.styles,
				settings.x,
				settings.y,
				settings.width,
				settings.height,
				settings.extendedStyles
			),
			parent
		),
		ITextListView(handle)
	{

	}
}
