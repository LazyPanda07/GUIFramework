#include "core.h"
#include "BaseListTextListView.h"

#include "Styles/Components/ListViews/ListTextListViewStyles.h"

using namespace std;

namespace gui_framework
{
	void BaseListTextListView::updateLocalization(size_t index, const wstring& localizedText)
	{
		ITextListView::changeTextItem(localizedText, index);
	}

	BaseListTextListView::BaseListTextListView(const wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent) :
		BaseListListView
		(
			listViewName,
			settings,
			styles::ListTextListViewStyles(),
			parent
		),
		ITextListView(handle)
	{

	}

	json::JSONBuilder BaseListTextListView::getStructure() const
	{
		using json::utility::jsonObject;

		uint32_t codepage = ISerializable::getCodepage();
		json::JSONBuilder builder = BaseListView::getStructure();
		jsonObject& current = get<jsonObject>(builder[utility::to_string(windowName, codepage)]);
		vector<jsonObject> values;
		size_t size = this->size();

		if (size)
		{
			for (size_t i = 0; i < size; i++)
			{
				json::utility::appendArray(utility::to_string(this->getItemText(i), codepage), values);
			}

			current.data.push_back({ "listViewTextValues"s, move(values) });
		}

		return builder;
	}

	LRESULT BaseListTextListView::addTextItem(const string& localizationKey)
	{
		this->addLocalizationKey(localizationKey);

		return ITextListView::addTextItem(localizationKey);
	}

	LRESULT BaseListTextListView::insertTextItem(const string& localizationKey, size_t index)
	{
		this->addLocalizationKey(localizationKey);

		return ITextListView::insertTextItem(localizationKey, index);
	}

	LRESULT BaseListTextListView::changeTextItem(const string& localizationKey, size_t index)
	{
		this->addLocalizationKey(localizationKey);

		return ITextListView::changeTextItem(localizationKey, index);
	}
}
