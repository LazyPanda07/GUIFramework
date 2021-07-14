#include "pch.h"
#include "IconListViewCreator.h"

#include "Components/ListViews/IconListView.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		BaseComponent* IconListViewCreator::create(const wstring& windowName, const utility::ComponentSettings& settings, const any& additionalData, BaseComponent* parent)
		{
			auto [type, data] = any_cast<tuple<utility::iconListViewType, vector<filesystem::path>>>(additionalData);

			IconListView* result = new IconListView(windowName, utility::ComponentSettings(settings.x, settings.y, settings.width, settings.height), parent, type);

			for (const auto& i : data)
			{
				result->addIconItem(i);
			}

			return result;
		}
	}
}
