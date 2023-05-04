#include "TextListView.h"

using namespace std;

namespace gui_framework
{
	TextListView::TextListView(const wstring& listViewName, const utility::ComponentSettings& settings, BaseComposite* parent) :
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

		json::JSONBuilder builder = BaseTextListView::getStructure();
		jsonObject& current = get<jsonObject>(builder[utility::to_string(windowName, ISerializable::getCodepage())]);

		return builder;
	}
}
