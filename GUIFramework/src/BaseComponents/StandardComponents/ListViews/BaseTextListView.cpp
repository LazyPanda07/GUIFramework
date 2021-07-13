#include "pch.h"
#include "BaseTextListView.h"

using namespace std;

namespace gui_framework
{
	BaseTextListView::BaseTextListView(const wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent) :
		BaseListView
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
