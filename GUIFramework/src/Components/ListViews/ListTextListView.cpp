#include "pch.h"
#include "ListTextListView.h"

using namespace std;

namespace gui_framework
{
	ListTextListView::ListTextListView(const wstring& listViewName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent) :
		BaseComponent
		(
			wstring(standard_classes::listView),
			listViewName,
			utility::ComponentSettings
			(
				LVS_LIST,
				x,
				y,
				width,
				height
			),
			parent
		),
		BaseListTextListView
		(
			listViewName,
			utility::ComponentSettings
			(
				NULL,
				x,
				y,
				width,
				height
			),
			parent
		)
	{

	}
}
