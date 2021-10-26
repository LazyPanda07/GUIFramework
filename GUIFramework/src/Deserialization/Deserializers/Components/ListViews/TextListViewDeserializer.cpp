#include "TextListViewDeserializer.h"

#include "Deserialization/Parsers/ListViews/TextListViewParser.h"

using namespace std;

namespace gui_framework
{
	namespace deserializers
	{
		BaseComponent* TextListViewDeserializer::deserialize(const string& componentName, const json::utility::objectSmartPointer<json::utility::jsonObject>& description, BaseComposite* parent) const
		{
			using json::utility::objectSmartPointer;
			using json::utility::jsonObject;

			parsers::TextListViewParser parser;

			parser.parse(description);

			TextListView* result = nullptr;
			uint32_t codepage = interfaces::ISerializable::getCodepage();
			const smartPointerType<utility::BaseComponentCreator>& creator = GUIFramework::get().getCreators().at(utility::getTypeHash<TextListView>());
			utility::AdditionalCreationData<TextListView> creationData(parser.values);

			result = static_cast<TextListView*>(creator->create(utility::to_wstring(componentName, codepage), parser.settings, creationData.getData(), parent));

			result->setBackgroundColor(parser.backgroundColor[0], parser.backgroundColor[1], parser.backgroundColor[2]);

			result->setTextColor(parser.textColor[0], parser.textColor[1], parser.textColor[2]);

			return result;
		}
	}
}
