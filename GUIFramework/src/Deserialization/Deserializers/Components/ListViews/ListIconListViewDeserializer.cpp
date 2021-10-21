#include "ListIconListViewDeserializer.h"

#include "Deserialization/Parsers/ListViews/IconListViewParser.h"

using namespace std;

namespace gui_framework
{
	namespace deserializers
	{
		BaseComponent* ListIconListViewDeserializer::deserialize(const string& componentName, const json::utility::objectSmartPointer<json::utility::jsonObject>& description, BaseComposite* parent) const
		{
			using json::utility::objectSmartPointer;
			using json::utility::jsonObject;

			parsers::IconListViewParser parser;

			parser.parse(description);

			ListIconListView* result = nullptr;
			uint32_t codepage = interfaces::ISerializable::getCodepage();
			const unique_ptr<utility::BaseComponentCreator>& creator = GUIFramework::get().getCreators().at(utility::getTypeHash<ListIconListView>());
			utility::AdditionalCreationData<ListIconListView> creationData(parser.type, parser.icons);

			result = static_cast<ListIconListView*>(creator->create(utility::to_wstring(componentName, codepage), parser.settings, creationData.getData(), parent));

			result->setBackgroundColor(parser.backgroundColor[0], parser.backgroundColor[1], parser.backgroundColor[2]);

			result->setStyles(parser.styles);

			return result;
		}
	}
}
