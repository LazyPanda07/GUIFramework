#include "ButtonDeserializer.h"

#include "Deserialization/Parsers/Buttons/ButtonParser.h"
#include "Utility/AdditionalCreationData/ButtonAdditionalCreationData.h"
#include "Components/Buttons/Button.h"
#include "GUIFramework.h"

using namespace std;

namespace gui_framework
{
	namespace deserializers
	{
		BaseComponent* ButtonDeserializer::deserialize(const string& componentName, const json::utility::jsonObject& description, BaseComposite* parent) const
		{
			using json::utility::jsonObject;

			parsers::ButtonParser parser;

			parser.parse(description);

			Button* result = nullptr;
			uint32_t codepage = interfaces::ISerializable::getCodepage();
			const smartPointerType<utility::BaseComponentCreator>& creator = GUIFramework::get().getCreators().at(utility::getTypeHash<Button>());
			utility::AdditionalCreationData<Button> creationData(parser.text, parser.onClickFunctionName, parser.onClickFunctionModule);

			result = static_cast<Button*>(creator->create(utility::to_wstring(componentName, codepage), parser.settings, creationData.getData(), parent));

			result->setBackgroundColor(parser.backgroundColor[0], parser.backgroundColor[1], parser.backgroundColor[2]);

			return result;
		}
	}
}
