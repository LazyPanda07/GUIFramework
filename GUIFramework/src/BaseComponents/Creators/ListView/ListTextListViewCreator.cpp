#include "pch.h"
#include "ListTextListViewCreator.h"

#include "Components/ListView/ListTextListView.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		BaseComponent* ListTextListViewCreator::create(const wstring& windowName, const utility::ComponentSettings& settings, const any& additionalData, BaseComponent* parent)
		{
			ListTextListView* result = new ListTextListView(windowName, settings.x, settings.y, settings.width, settings.height, parent);
			vector<wstring> data = any_cast<vector<wstring>>(additionalData);

			for (const auto& i : data)
			{
				result->addTextItem(i);
			}

			return result;
		}
	}
}