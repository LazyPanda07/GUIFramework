#include "headers.h"
#include "BaseListTextListView.h"

#include "Styles/Components/ListViews/ListTextListViewStyles.h"

using namespace std;

namespace gui_framework
{
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
		using json::utility::objectSmartPointer;

		uint32_t codepage = ISerializable::getCodepage();
		json::JSONBuilder builder = BaseListView::getStructure();
		objectSmartPointer<jsonObject>& current = get<objectSmartPointer<jsonObject>>(builder[utility::to_string(windowName, codepage)]);
		vector<objectSmartPointer<jsonObject>> values;
		size_t size = this->size();

		if (size)
		{
			for (size_t i = 0; i < size; i++)
			{
				json::utility::appendArray(utility::to_string(this->getItemText(i), codepage), values);
			}

			current->data.push_back({ "listViewTextValues"s, move(values) });
		}

		return builder;
	}
}
