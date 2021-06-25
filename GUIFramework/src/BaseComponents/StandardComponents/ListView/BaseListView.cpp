#include "pch.h"
#include "BaseListView.h"

using namespace std;

namespace gui_framework
{
	LRESULT BaseListView::addItem(const LVITEMW& item)
	{
		LRESULT result = SendMessageW(handle, LVM_INSERTITEM, NULL, reinterpret_cast<LPARAM>(&item));

		if (result != -1)
		{
			SendMessageW(handle, LVM_ISITEMVISIBLE, result, NULL);
		}

		return result;
	}

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
