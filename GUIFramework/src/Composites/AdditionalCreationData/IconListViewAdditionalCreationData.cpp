#include "pch.h"
#include "IconListViewAdditionalCreationData.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		AdditionalCreationData<IconListView>::AdditionalCreationData(utility::iconListViewType type, const vector<filesystem::path>& pathToIcons) :
			type(type),
			pathToIcons(pathToIcons)
		{
			
		}

		any AdditionalCreationData<IconListView>::getData() const
		{
			return make_any<tuple<iconListViewType, vector<filesystem::path>>>(type, pathToIcons);
		}

		AdditionalCreationData<ListIconListView>::AdditionalCreationData(utility::iconListViewType type, const vector<filesystem::path>& pathToIcons) :
			type(type),
			pathToIcons(pathToIcons)
		{

		}

		any AdditionalCreationData<ListIconListView>::getData() const
		{
			return make_any<tuple<iconListViewType, vector<filesystem::path>>>(type, pathToIcons);
		}
	}
}
