#include "headers.h"
#include "IconListView.h"

using namespace std;

namespace gui_framework
{
	IconListView::IconListView(const wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent, utility::iconListViewType type) :
		BaseIconListView
		(
			listViewName,
			settings,
			parent,
			type,
			type == utility::iconListViewType::icon ? standard_sizes::largeIconWidth : standard_sizes::smallIconWidth,
			type == utility::iconListViewType::icon ? standard_sizes::largeIconHeight : standard_sizes::smallIconHeight
		)
	{
		
	}

	size_t IconListView::getHash() const
	{
		return typeid(IconListView).hash_code();
	}

	json::JSONBuilder IconListView::getStructure() const
	{
		using json::utility::jsonObject;

		json::JSONBuilder builder = BaseIconListView::getStructure();
		jsonObject& current = get<jsonObject>(builder[utility::to_string(windowName, ISerializable::getCodepage())]);

		return builder;
	}
}
