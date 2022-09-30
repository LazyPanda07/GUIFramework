#include "Core.h"
#include "TextIconListViewAdditionalCreationData.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		AdditionalCreationData<TextIconListView>::AdditionalCreationData(iconListViewType type, const vector<pair<wstring, filesystem::path>>& items) :
			type(type),
			items(items)
		{

		}

		any AdditionalCreationData<TextIconListView>::getData() const
		{
			return make_any<tuple<iconListViewType, vector<pair<wstring, filesystem::path>>>>(type, items);
		}

		AdditionalCreationData<ListTextIconListView>::AdditionalCreationData(iconListViewType type, const vector<pair<wstring, filesystem::path>>& items) :
			type(type),
			items(items)
		{

		}

		any AdditionalCreationData<ListTextIconListView>::getData() const
		{
			return make_any<tuple<iconListViewType, vector<pair<wstring, filesystem::path>>>>(type, items);
		}
	}
}
