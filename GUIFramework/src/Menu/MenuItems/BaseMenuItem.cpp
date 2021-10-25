#include "headers.h"
#include "BaseMenuItem.h"

using namespace std;

namespace gui_framework
{
	BaseMenuItem::BaseMenuItem(const wstring& text) :
		IMenuItem
		(
			text,
			standard_menu_items::menuItem
		)
	{

	}

	tuple<uint32_t, uint64_t> BaseMenuItem::getCreationData() const
	{
		return make_tuple(static_cast<uint32_t>(NULL), NULL);
	}
}
