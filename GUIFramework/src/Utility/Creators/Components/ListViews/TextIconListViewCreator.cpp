#include "TextIconListViewCreator.h"

#include "Components/ListViews/TextIconListView.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		BaseComponent* TextIconListViewCreator::create(const wstring& windowName, const utility::ComponentSettings& settings, const any& additionalData, BaseComposite* parent)
		{
			auto [type, data] = any_cast<tuple<utility::iconListViewType, vector<pair<wstring, filesystem::path>>>>(additionalData);

			TextIconListView* result = new TextIconListView(windowName, settings, parent, type);

			for (const auto& i : data)
			{
				static_cast<interfaces::ITextIconListView*>(result)->addTextIconItem(i.first, i.second);
			}

			return result;
		}
	}
}
