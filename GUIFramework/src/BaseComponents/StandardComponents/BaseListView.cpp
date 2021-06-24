#include "pch.h"
#include "BaseListView.h"

using namespace std;

namespace gui_framework
{
	BaseListView::BaseListView(const wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent) :
		BaseComponent
		(
			wstring(standard_classes::listView),
			listViewName,
			settings,
			parent
		)
	{

	}
}
