#include "headers.h"
#include "TextIconListView.h"

using namespace std;

namespace gui_framework
{
	TextIconListView::TextIconListView(const wstring& listViewName, const utility::ComponentSettings& settings, BaseComponent* parent, utility::iconListViewType type) :
		BaseTextIconListView
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

	size_t TextIconListView::getHash() const
	{
		return typeid(TextIconListView).hash_code();
	}

	json::JSONBuilder TextIconListView::getStructure() const
	{
		using json::utility::jsonObject;
		using json::utility::objectSmartPointer;

		json::JSONBuilder builder = BaseTextIconListView::getStructure();
		objectSmartPointer<jsonObject>& current = get<objectSmartPointer<jsonObject>>(builder[utility::to_string(windowName, ISerializable::getCodepage())]);

		return builder;
	}
}
