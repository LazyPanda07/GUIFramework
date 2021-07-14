#include "pch.h"
#include "BaseListTextListView.h"

#include "Styles/Components/ListViews/ListTextListViewStyles.h"

using namespace std;

namespace gui_framework
{
	BaseListTextListView::BaseListTextListView(const wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent) :
		BaseListListView
		(
			listViewName,
			settings,
			styles::ListTextListViewStyles(),
			parent
		),
		ITextListView(handle)
	{

	}
}
