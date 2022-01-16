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

	size_t ListTextListView::getHash() const
	{
		return typeid(ListTextListView).hash_code();
	}

	json::JSONBuilder ListTextListView::getStructure() const
	{
		using json::utility::jsonObject;

		json::JSONBuilder builder = BaseListTextListView::getStructure();
		jsonObject& current = get<jsonObject>(builder[utility::to_string(windowName, ISerializable::getCodepage())]);

		return builder;
	}
}
