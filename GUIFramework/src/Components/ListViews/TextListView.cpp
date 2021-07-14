#include "pch.h"
#include "TextListView.h"

using namespace std;

namespace gui_framework
{
	TextListView::TextListView(const wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent) :
		BaseTextListView
		(
			listViewName,
			settings,
			parent
		)
	{

	}
}
