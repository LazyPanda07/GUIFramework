#include "headers.h"
#include "TextListViewCreator.h"

#include "Components/ListViews/TextListView.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		BaseComponent* TextListViewCreator::create(const wstring& windowName, const utility::ComponentSettings& settings, const any& additionalData, BaseComponent* parent)
		{
			TextListView* result = new TextListView(windowName, settings, parent);
			vector<wstring> data = any_cast<vector<wstring>>(additionalData);

			for (const auto& i : data)
			{
				result->addTextItem(i);
			}

			return result;
		}
	}
}
