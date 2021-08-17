#include "pch.h"
#include "BaseIconListView.h"

#include "Styles/Components/ListViews/IconListViewStyles.h"
#include "Exceptions/NotImplemented.h"

using namespace std;

namespace gui_framework
{
	BaseIconListView::BaseIconListView(const wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent, utility::iconListViewType type, uint16_t iconsWidth, uint16_t iconsHeight, size_t count) :
		BaseListView
		(
			listViewName,
			settings,
			styles::IconListViewStyles(type),
			parent
		),
		IIconListView(handle, icons),
		icons(iconsWidth, iconsHeight, count)
	{
		SendMessageW(handle, LVM_SETIMAGELIST, type == utility::iconListViewType::icon ? LVSIL_NORMAL : LVSIL_SMALL, reinterpret_cast<LPARAM>(icons.getImageList()));
	}

	void BaseIconListView::setTextColor(uint8_t red, uint8_t green, uint8_t blue)
	{
		throw exceptions::NotImplemented(__FUNCTION__, "BaseIconListView");
	}

	json::JSONBuilder BaseIconListView::getStructure() const
	{
		using json::utility::jsonObject;
		using json::utility::objectSmartPointer;

		uint32_t codepage = ISerializable::getCodepage();
		json::JSONBuilder builder = BaseListView::getStructure();
		objectSmartPointer<jsonObject>& current = get<objectSmartPointer<jsonObject>>(builder[utility::to_string(windowName, codepage)]);

		if (this->size())
		{
			icons.loadBaseLoadableHolderStructure(current).first = "listViewValues";
		}

		return builder;
	}
}
