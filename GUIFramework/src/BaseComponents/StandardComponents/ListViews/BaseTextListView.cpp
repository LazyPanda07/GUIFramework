#include "pch.h"
#include "BaseTextListView.h"

#include "Styles/Components/ListViews/TextListViewStyles.h"

using namespace std;

namespace gui_framework
{
	BaseTextListView::BaseTextListView(const wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent) :
		BaseListView
		(
			listViewName,
			settings,
			styles::TextListViewStyles(),
			parent
		),
		ITextListView(handle)
	{

	}
}
