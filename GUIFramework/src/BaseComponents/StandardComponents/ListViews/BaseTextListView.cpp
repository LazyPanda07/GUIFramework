#include "pch.h"
#include "BaseTextListView.h"

#include "Styles/Components/ListViews/TextListViewStyles.h"

using namespace std;

namespace gui_framework
{
	BaseTextListView::BaseTextListView(const wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent) :
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
		using json::utility::objectSmartPointer;

		uint32_t codepage = ISerializable::getCodepage();
		json::JSONBuilder builder = BaseListView::getStructure();
		objectSmartPointer<jsonObject>& current = get<objectSmartPointer<jsonObject>>(builder[utility::to_string(windowName, codepage)]);
		vector<objectSmartPointer<jsonObject>> values;
		size_t size = this->size();

		__utility::changeClassName(current, serialized_classes::textListView);
		
		if (size)
		{
			for (size_t i = 0; i < size; i++)
			{
				json::utility::appendArray(utility::to_string(this->getItemText(i), codepage), values);
			}

			current->data.push_back({ "listViewValues"s, move(values) });
		}

		return builder;
	}
}
