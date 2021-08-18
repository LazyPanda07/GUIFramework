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
		vector<objectSmartPointer<jsonObject>> iconValues;
		size_t size = this->size();

		current->data.push_back({ "imagesWidth"s, static_cast<uint64_t>(icons.getImagesWidth()) });
		current->data.push_back({ "imagesHeight"s, static_cast<uint64_t>(icons.getImagesHeight()) });

		if (size)
		{
			for (size_t i = 0; i < size; i++)
			{
				auto [text, _, pathToIcon] = this->getTextIconItem(i);

				json::utility::appendArray(utility::to_string(text, codepage), textValues);

				json::utility::appendArray(pathToIcon.string(), iconValues);
			}

			current->data.push_back({ "listViewTextValues"s, move(textValues) });
			current->data.push_back({ "listViewIconValues"s, move(iconValues) });
		}

		return builder;
	}
}
