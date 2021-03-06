#include "IconListViewDeserializer.h"

#include "Deserialization/Parsers/ListViews/IconListViewParser.h"
#include "GUIFramework.h"
#include "Utility/AdditionalCreationData/IconListViewAdditionalCreationData.h"

using namespace std;

namespace gui_framework
{
	namespace deserializers
	{
		BaseComponent* IconListViewDeserializer::deserialize(const string& componentName, const json::utility::jsonObject& description, BaseComposite* parent) const
		{
			using json::utility::jsonObject;

			parsers::IconListViewParser parser;

			parser.parse(description);

			IconListView* result = nullptr;
			uint32_t codepage = interfaces::ISerializable::getCodepage();
			const smartPointerType<utility::BaseComponentCreator>& creator = GUIFramework::get().getCreators().at(utility::getTypeHash<IconListView>());
			utility::AdditionalCreationData<IconListView> creationData(parser.type, parser.icons);

			result = static_cast<IconListView*>(creator->create(utility::to_wstring(componentName, codepage), parser.settings, creationData.getData(), parent));

			result->setBackgroundColor(parser.backgroundColor[0], parser.backgroundColor[1], parser.backgroundColor[2]);

			return result;
		}
	}
}
