#include "BaseListListView.h"

using namespace std;

namespace gui_framework
{
	BaseListListView::BaseListListView(const wstring& listViewName, const utility::ComponentSettings& settings, const styles::ListListViewStyles& styles, BaseComposite* parent) :
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
