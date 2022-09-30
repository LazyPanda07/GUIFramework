#include "Core.h"
#include "BaseTextListView.h"

#include "Styles/Components/ListViews/TextListViewStyles.h"

using namespace std;

namespace gui_framework
{
	void BaseTextListView::updateLocalization(size_t index, const wstring& localizedText)
	{
		ITextListView::changeTextItem(localizedText, index);
	}

	BaseTextListView::BaseTextListView(const wstring& listViewName, const utility::ComponentSettings& settings, BaseComposite* parent) :
		BaseListView
		(
			listViewName,
			settings,
			styles::TextListViewStyles(),
			parent
		),
		ITextListView(handle)
	{

	}

	json::JSONBuilder BaseTextListView::getStructure() const
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

	LRESULT BaseTextListView::addTextItem(const string& localizationKey)
	{
		this->addLocalizationKey(localizationKey);

		return ITextListView::addTextItem(localizationKey);
	}

	LRESULT BaseTextListView::insertTextItem(const string& localizationKey, size_t index)
	{
		this->addLocalizationKey(localizationKey);

		return ITextListView::insertTextItem(localizationKey, index);
	}

	LRESULT BaseTextListView::changeTextItem(const string& localizationKey, size_t index)
	{
		this->addLocalizationKey(localizationKey);

		return ITextListView::changeTextItem(localizationKey, index);
	}
}
