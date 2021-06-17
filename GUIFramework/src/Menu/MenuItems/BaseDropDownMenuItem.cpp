#include "pch.h"
#include "BaseDropDownMenuItem.h"

using namespace std;

namespace gui_framework
{
	BaseDropDownMenuItem::BaseDropDownMenuItem(const wstring& text, HMENU popupMenuHandle) :
		IMenuItem
		(
			text,
			string(standard_menu_items::dropDownMenuItem)
		),
		popupMenuHandle(popupMenuHandle)
	{

	}

	tuple<uint32_t, uint64_t> BaseDropDownMenuItem::getCreationData() const
	{
		return make_tuple(static_cast<uint32_t>(MF_POPUP), reinterpret_cast<uint64_t>(popupMenuHandle));
	}
}
