#include "headers.h"
#include "TextListView.h"

using namespace std;

namespace gui_framework
{
	TextListView::TextListView(const wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent) :
		BaseTextListView
		(
			listViewName,
			settings,
			parent
		)
	{

	}

	size_t TextListView::getHash() const
	{
		return typeid(TextListView).hash_code();
	}

	json::JSONBuilder TextListView::getStructure() const
	{
		using json::utility::jsonObject;
		using json::utility::objectSmartPointer;

		json::JSONBuilder builder = BaseTextListView::getStructure();
		objectSmartPointer<jsonObject>& current = get<objectSmartPointer<jsonObject>>(builder[utility::to_string(windowName, ISerializable::getCodepage())]);

		return builder;
	}
}
