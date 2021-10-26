#include "headers.h"
#include "DropDownMenuItem.h"

using namespace std;

namespace gui_framework
{
	DropDownMenuItem::DropDownMenuItem(const wstring& text, HMENU popupMenuHandle) :
		IMenuItem
		(
			text,
			standard_menu_items::dropDownMenuItem
		),
		popupMenuHandle(popupMenuHandle)
	{

	}

	void DropDownMenuItem::processMessage()
	{

	}

	tuple<uint32_t, uint64_t> DropDownMenuItem::getCreationData() const
	{
		return make_tuple(static_cast<uint32_t>(MF_POPUP), reinterpret_cast<uint64_t>(popupMenuHandle));
	}

	json::JSONBuilder DropDownMenuItem::getStructure() const
	{
		json::JSONBuilder builder = IMenuItem::getStructure();

		builder.append("popupId"s, reinterpret_cast<uint64_t>(popupMenuHandle));

		return builder;
	}
}
