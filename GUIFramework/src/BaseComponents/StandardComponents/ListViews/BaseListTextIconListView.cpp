#include "pch.h"
#include "BaseListTextIconListView.h"

#include "Styles/Components/ListViews/ListIconListViewStyles.h"

using namespace std;

namespace gui_framework
{
	BaseListTextIconListView::BaseListTextIconListView(const wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent, utility::iconListViewType type, uint16_t iconsWidth, uint16_t iconsHeight, size_t count) :
		BaseListListView
		(
			listViewName,
			settings,
			styles::ListIconListViewStyles(type),
			parent
		),
		ITextIconListView(handle, icons),
		icons(iconsWidth, iconsHeight, count)
	{
		SendMessageW(handle, LVM_SETIMAGELIST, type == utility::iconListViewType::icon ? LVSIL_NORMAL : LVSIL_SMALL, reinterpret_cast<LPARAM>(icons.getImageList()));
	}

	json::JSONBuilder BaseListTextIconListView::getStructure() const
	{
		using json::utility::jsonObject;
		using json::utility::objectSmartPointer;

		uint32_t codepage = ISerializable::getCodepage();
		json::JSONBuilder builder = BaseListView::getStructure();
		objectSmartPointer<jsonObject>& current = get<objectSmartPointer<jsonObject>>(builder[utility::to_string(windowName, codepage)]);
		vector<objectSmartPointer<jsonObject>> textValues;
		size_t size = this->size();

		__utility::changeClassName(current, serialized_classes::listTextIconListView);

		if (size)
		{
			for (size_t i = 0; i < size; i++)
			{
				json::utility::appendArray(utility::to_string(get<wstring>(this->getTextIconItem(i)), codepage), textValues);
			}

			auto& iconsHolderStructure = icons.loadBaseLoadableHolderStructure(current);
			auto& object = get<objectSmartPointer<jsonObject>>(iconsHolderStructure.second);

			iconsHolderStructure.first = "listViewValues";

			object->data.push_back({ "listViewTextValue"s, move(textValues) });
		}

		return builder;
	}
}
