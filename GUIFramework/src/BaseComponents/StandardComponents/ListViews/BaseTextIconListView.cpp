#include "BaseTextIconListView.h"

#include "Styles/Components/ListViews/IconListViewStyles.h"

using namespace std;

namespace gui_framework
{
	void BaseTextIconListView::updateLocalization(size_t index, wstring_view localizedText)
	{
		auto&& [text, iconIndex, pathToIcon] = this->getTextIconItem(index);

		ITextIconListView::changeTextIconItem(localizedText, pathToIcon, index);
	}

	BaseTextIconListView::BaseTextIconListView(const wstring& listViewName, const utility::ComponentSettings& settings, BaseComposite* parent, utility::iconListViewType type, uint16_t iconsWidth, uint16_t iconsHeight, size_t count) :
		BaseListView
		(
			listViewName,
			settings,
			styles::IconListViewStyles(type),
			parent
		),
		ITextIconListView(handle, icons),
		icons(iconsWidth, iconsHeight, count)
	{
		SendMessageW(handle, LVM_SETIMAGELIST, type == utility::iconListViewType::icon ? LVSIL_NORMAL : LVSIL_SMALL, reinterpret_cast<LPARAM>(icons.getImageList()));
	}

	json::JSONBuilder BaseTextIconListView::getStructure() const
	{
		using json::utility::jsonObject;

		uint32_t codepage = ISerializable::getCodepage();
		json::JSONBuilder builder = BaseListView::getStructure();
		jsonObject& current = get<jsonObject>(builder[utility::to_string(windowName, codepage)]);
		vector<jsonObject> textValues;
		vector<jsonObject> iconValues;
		size_t size = this->size();

		current.data.push_back({ "imagesWidth"s, static_cast<uint64_t>(icons.getImagesWidth()) });
		current.data.push_back({ "imagesHeight"s, static_cast<uint64_t>(icons.getImagesHeight()) });

		if (size)
		{
			for (size_t i = 0; i < size; i++)
			{
				auto [text, _, pathToIcon] = this->getTextIconItem(i);

				json::utility::appendArray(utility::to_string(text, codepage), textValues);

				json::utility::appendArray(pathToIcon.string(), iconValues);
			}

			current.data.push_back({ "listViewTextValues"s, move(textValues) });
			current.data.push_back({ "listViewIconValues"s, move(iconValues) });
		}

		return builder;
	}

	LRESULT BaseTextIconListView::addTextIconItem(string_view localizationKey, const filesystem::path& pathToIcon)
	{
		this->addLocalizationKey(localizationKey);

		return ITextIconListView::addTextIconItem(localizationKey, pathToIcon);
	}

	LRESULT BaseTextIconListView::insertTextIconItem(string_view localizationKey, const filesystem::path& pathToIcon, size_t index)
	{
		this->addLocalizationKey(localizationKey);

		return ITextIconListView::insertTextIconItem(localizationKey, pathToIcon, index);
	}

	LRESULT BaseTextIconListView::changeTextIconItem(string_view localizationKey, const filesystem::path& pathToIcon, size_t index)
	{
		this->addLocalizationKey(localizationKey);

		return ITextIconListView::changeTextIconItem(localizationKey, pathToIcon, index);
	}
}
