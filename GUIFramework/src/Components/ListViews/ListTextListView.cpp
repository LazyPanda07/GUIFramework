#include "headers.h"
#include "ListTextListView.h"

using namespace std;

namespace gui_framework
{
	ListTextListView::ListTextListView(const wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent) :
		BaseListTextListView
		(
			listViewName,
			settings,
			parent
		)
	{

	}

	json::JSONBuilder ListTextListView::getStructure() const
	{
		using json::utility::jsonObject;
		using json::utility::objectSmartPointer;

		json::JSONBuilder builder = BaseListTextListView::getStructure();
		objectSmartPointer<jsonObject>& current = get<objectSmartPointer<jsonObject>>(builder[utility::to_string(windowName, ISerializable::getCodepage())]);

		__utility::changeClassName(current, serialized_classes::listTextListView);

		return builder;
	}
}
