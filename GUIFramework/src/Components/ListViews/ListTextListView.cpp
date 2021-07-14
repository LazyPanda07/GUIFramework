#include "pch.h"
#include "ListTextListView.h"

using namespace std;

namespace gui_framework
{
	ListTextListView::ListTextListView(const wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent) :
		BaseListTextListView
		(
			listViewName,
			settings,
			parent
		)
	{

	}
}
