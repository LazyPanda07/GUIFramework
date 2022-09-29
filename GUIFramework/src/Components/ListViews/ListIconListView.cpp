#include "core.h"
#include "ListIconListView.h"

using namespace std;

namespace gui_framework
{
	ListIconListView::ListIconListView(const wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent, utility::iconListViewType type) :
		BaseListIconListView
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

	size_t ListIconListView::getHash() const
	{
		return typeid(ListIconListView).hash_code();
	}

	json::JSONBuilder ListIconListView::getStructure() const
	{
		using json::utility::jsonObject;

		json::JSONBuilder builder = BaseListIconListView::getStructure();
		jsonObject& current = get<jsonObject>(builder[utility::to_string(windowName, ISerializable::getCodepage())]);

		return builder;
	}
}
