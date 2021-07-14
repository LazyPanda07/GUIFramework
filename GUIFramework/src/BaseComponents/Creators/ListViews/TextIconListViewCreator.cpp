#include "pch.h"
#include "TextIconListViewCreator.h"

#include "Components/ListViews/TextIconListView.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		BaseComponent* TextIconListViewCreator::create(const wstring& windowName, const utility::ComponentSettings& settings, const any& additionalData, BaseComponent* parent)
		{
			auto [type, data] = any_cast<tuple<utility::iconListViewType, vector<pair<wstring, filesystem::path>>>>(additionalData);

			TextIconListView* result = new TextIconListView(windowName, utility::ComponentSettings(settings.x, settings.y, settings.width, settings.height), parent, type);

			for (const auto& i : data)
			{
				result->addTextIconItem(i.first, i.second);
			}

			return result;
		}
	}
}
