#include "headers.h"
#include "ListTextListViewCreator.h"

#include "Components/ListViews/ListTextListView.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		BaseComponent* ListTextListViewCreator::create(const wstring& windowName, const utility::ComponentSettings& settings, const any& additionalData, BaseComponent* parent)
		{
			ListTextListView* result = new ListTextListView(windowName, settings, parent);
			vector<wstring> data = any_cast<vector<wstring>>(additionalData);

			for (const auto& i : data)
			{
				result->addTextItem(i);
			}

			return result;
		}
	}
}
