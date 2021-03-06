#include "ListTextListViewDeserializer.h"

#include "Deserialization/Parsers/ListViews/TextListViewParser.h"
#include "GUIFramework.h"
#include "Utility/AdditionalCreationData/TextListViewAdditionalCreationData.h"

using namespace std;

namespace gui_framework
{
	namespace deserializers
	{
		BaseComponent* ListTextListViewDeserializer::deserialize(const string& componentName, const json::utility::jsonObject& description, BaseComposite* parent) const
		{
			using json::utility::jsonObject;

			parsers::TextListViewParser parser;

			parser.parse(description);

			ListTextListView* result = nullptr;
			uint32_t codepage = interfaces::ISerializable::getCodepage();
			const smartPointerType<utility::BaseComponentCreator>& creator = GUIFramework::get().getCreators().at(utility::getTypeHash<ListTextListView>());
			utility::AdditionalCreationData<ListTextListView> creationData(parser.values);

			result = static_cast<ListTextListView*>(creator->create(utility::to_wstring(componentName, codepage), parser.settings, creationData.getData(), parent));

			result->setBackgroundColor(parser.backgroundColor[0], parser.backgroundColor[1], parser.backgroundColor[2]);

			result->setTextColor(parser.textColor[0], parser.textColor[1], parser.textColor[2]);

			return result;
		}
	}
}
