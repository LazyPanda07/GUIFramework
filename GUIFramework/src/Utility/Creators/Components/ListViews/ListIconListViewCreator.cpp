#include "headers.h"
#include "ListIconListViewCreator.h"

#include "Components/ListViews/ListIconListView.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		BaseComponent* ListIconListViewCreator::create(const wstring& windowName, const utility::ComponentSettings& settings, const any& additionalData, BaseComponent* parent)
		{
			auto [type, data] = any_cast<tuple<utility::iconListViewType, vector<filesystem::path>>>(additionalData);

			ListIconListView* result = new ListIconListView(windowName, settings, parent, type);

			for (const auto& i : data)
			{
				result->addIconItem(i);
			}

			return result;
		}
	}
}
