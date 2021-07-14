#include "pch.h"
#include "BaseListListView.h"

using namespace std;

namespace gui_framework
{
	BaseListListView::BaseListListView(const wstring& listViewName, const utility::ComponentSettings& settings, const styles::ListListViewStyles& styles, BaseComponent* parent) :
		BaseListView
		(
			listViewName,
			settings,
			styles,
			parent
		)
	{
		
	}
}
