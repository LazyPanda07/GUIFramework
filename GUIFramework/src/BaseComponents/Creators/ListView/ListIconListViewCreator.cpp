#include "pch.h"
#include "ListIconListViewCreator.h"

#include "Components/ListView/ListIconListView.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		BaseComponent* ListIconListViewCreator::create(const wstring& windowName, const utility::ComponentSettings& settings, const any& additionalData, BaseComponent* parent)
		{
			auto [type, data] = any_cast<tuple<utility::iconListViewType, vector<filesystem::path>>>(additionalData);

			ListIconListView* iconListView = new ListIconListView(windowName, settings.x, settings.y, settings.width, settings.height, parent, type);

			for (const auto& i : data)
			{
				iconListView->addIconItem(i);
			}

			return iconListView;
		}
	}
}
