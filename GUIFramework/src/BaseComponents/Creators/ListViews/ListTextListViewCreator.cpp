#include "pch.h"
#include "ListTextListViewCreator.h"

#include "Components/ListViews/ListTextListView.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		BaseComponent* ListTextListViewCreator::create(const wstring& windowName, const utility::ComponentSettings& settings, const any& additionalData, BaseComponent* parent)
		{
			ListTextListView* result = new ListTextListView(windowName, utility::ComponentSettings(settings.x, settings.y, settings.width, settings.height), parent);
			vector<wstring> data = any_cast<vector<wstring>>(additionalData);

			for (const auto& i : data)
			{
				result->addTextItem(i);
			}

			return result;
		}
	}
}
