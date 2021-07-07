#include "pch.h"
#include "IconListViewCreator.h"

#include "Components/ListView/IconListView.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		BaseComponent* IconListViewCreator::create(const wstring& windowName, const utility::ComponentSettings& settings, const any& additionalData, BaseComponent* parent)
		{
			auto [type, data] = any_cast<tuple<utility::iconListViewType, vector<filesystem::path>>>(additionalData);

			IconListView* iconListView = new IconListView(windowName, settings.x, settings.y, settings.width, settings.height, parent, type);

			for (const auto& i : data)
			{
				iconListView->addIconItem(i);
			}

			return iconListView;
		}
	}
}