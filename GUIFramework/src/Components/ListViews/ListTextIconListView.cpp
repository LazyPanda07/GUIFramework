#include "headers.h"
#include "ListTextIconListView.h"

using namespace std;

namespace gui_framework
{
	ListTextIconListView::ListTextIconListView(const wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent, utility::iconListViewType type) :
		BaseListTextIconListView
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

	json::JSONBuilder ListTextIconListView::getStructure() const
	{
		using json::utility::jsonObject;
		using json::utility::objectSmartPointer;

		json::JSONBuilder builder = BaseListTextIconListView::getStructure();
		objectSmartPointer<jsonObject>& current = get<objectSmartPointer<jsonObject>>(builder[utility::to_string(windowName, ISerializable::getCodepage())]);

		__utility::changeClassName(current, serialized_classes::listTextIconListView);

		return builder;
	}
}
