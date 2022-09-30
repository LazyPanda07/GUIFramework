#include "BaseListIconListView.h"

#include "Styles/Components/ListViews/ListIconListViewStyles.h"
#include "Exceptions/NotImplemented.h"

using namespace std;

namespace gui_framework
{
	BaseListIconListView::BaseListIconListView(const wstring& listViewName, const utility::ComponentSettings& settings, BaseComposite* parent, utility::iconListViewType type, uint16_t iconsWidth, uint16_t iconsHeight, size_t count) :
		BaseListListView
		(
			listViewName,
			settings,
			styles::ListIconListViewStyles(type),
			parent
		),
		IIconListView(handle, icons),
		icons(iconsWidth, iconsHeight, count)
	{
		SendMessageW(handle, LVM_SETIMAGELIST, type == utility::iconListViewType::icon ? LVSIL_NORMAL : LVSIL_SMALL, reinterpret_cast<LPARAM>(icons.getImageList()));
	}

	void BaseListIconListView::setTextColor(uint8_t red, uint8_t green, uint8_t blue)
	{
		__utility::throwNotImplementedException(__FUNCTION__, "BaseListIconListView"sv);
	}

	json::JSONBuilder BaseListIconListView::getStructure() const
	{
		using json::utility::jsonObject;

		uint32_t codepage = ISerializable::getCodepage();
		json::JSONBuilder builder = BaseListView::getStructure();
		jsonObject& current = get<jsonObject>(builder[utility::to_string(windowName, codepage)]);
		vector<jsonObject> values;
		size_t size = this->size();

		current.data.push_back({ "imagesWidth"s, static_cast<uint64_t>(icons.getImagesWidth()) });
		current.data.push_back({ "imagesHeight"s, static_cast<uint64_t>(icons.getImagesHeight()) });

		if (size)
		{
			for (size_t i = 0; i < size; i++)
			{
				json::utility::appendArray(this->getIconPath(i).string(), values);
			}

			current.data.push_back({ "listViewIconValues"s, move(values) });
		}

		return builder;
	}
}
