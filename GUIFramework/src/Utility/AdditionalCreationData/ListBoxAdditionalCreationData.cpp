#include "core.h"
#include "ListBoxAdditionalCreationData.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		AdditionalCreationData<ListBox>::AdditionalCreationData(const vector<wstring>& values, bool isSorting) :
			values(values),
			isSorting(isSorting)
		{

		}

		any AdditionalCreationData<ListBox>::getData() const
		{
			return make_any<tuple<vector<wstring>, bool>>(values, isSorting);
		}

		AdditionalCreationData<MultipleSelectListBox>::AdditionalCreationData(const vector<wstring>& values, bool isSorting) :
			values(values),
			isSorting(isSorting)
		{

		}

		any AdditionalCreationData<MultipleSelectListBox>::getData() const
		{
			return make_any<tuple<vector<wstring>, bool>>(values, isSorting);
		}
	}
}
