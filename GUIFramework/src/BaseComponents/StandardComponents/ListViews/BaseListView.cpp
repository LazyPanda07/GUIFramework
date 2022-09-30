#include "Core.h"
#include "BaseListView.h"

using namespace std;

namespace gui_framework
{
	BaseListView::BaseListView(const wstring& listViewName, const utility::ComponentSettings& settings, const styles::ListViewStyles& styles, BaseComposite* parent) :
		BaseComponent
		(
			standard_classes::listView,
			listViewName,
			settings,
			styles,
			parent
		)
	{

	}

	void BaseListView::setBackgroundColor(uint8_t red, uint8_t green, uint8_t blue)
	{
		BaseComponent::setBackgroundColor(red, green, blue);

		SendMessageW(handle, LVM_SETBKCOLOR, NULL, static_cast<LPARAM>(backgroundColor));
	}

	void BaseListView::setTextColor(uint8_t red, uint8_t green, uint8_t blue)
	{
		BaseComponent::setTextColor(red, green, blue);

		SendMessageW(handle, LVM_SETTEXTCOLOR, NULL, static_cast<LPARAM>(textColor));

		SendMessageW(handle, LVM_SETTEXTBKCOLOR, NULL, static_cast<LPARAM>(backgroundColor));
	}
}
