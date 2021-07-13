#include "pch.h"
#include "TextListView.h"

using namespace std;

namespace gui_framework
{
	TextListView::TextListView(const wstring& listViewName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent) :
		BaseTextListView
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
