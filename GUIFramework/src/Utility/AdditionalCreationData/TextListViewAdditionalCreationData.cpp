#include "TextListViewAdditionalCreationData.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		AdditionalCreationData<TextListView>::AdditionalCreationData(const vector<wstring>& items) :
			items(items)
		{

		}

		any AdditionalCreationData<TextListView>::getData() const
		{
			return make_any<vector<wstring>>(items);
		}

		AdditionalCreationData<ListTextListView>::AdditionalCreationData(const vector<wstring>& items) :
			items(items)
		{

		}

		any AdditionalCreationData<ListTextListView>::getData() const
		{
			return make_any<vector<wstring>>(items);
		}
	}
}
