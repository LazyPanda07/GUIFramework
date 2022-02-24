#include "headers.h"
#include "ListTextIconListViewCreator.h"

#include "Components/ListViews/ListTextIconListView.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		BaseComponent* ListTextIconListViewCreator::create(const wstring& windowName, const utility::ComponentSettings& settings, const any& additionalData, BaseComponent* parent)
		{
			auto [type, data] = any_cast<tuple<utility::iconListViewType, vector<pair<wstring, filesystem::path>>>>(additionalData);

			ListTextIconListView* result = new ListTextIconListView(windowName, settings, parent, type);

			for (const auto& i : data)
			{
				static_cast<interfaces::ITextIconListView*>(result)->addTextIconItem(i.first, i.second);
			}

			return result;
		}
	}
}
