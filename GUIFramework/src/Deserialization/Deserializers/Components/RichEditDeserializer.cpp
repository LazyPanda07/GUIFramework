#include "RichEditDeserializer.h"

#include "Deserialization/Parsers/RichEditParser.h"

using namespace std;

namespace gui_framework
{
	namespace deserializers
	{
		BaseComponent* RichEditDeserializer::deserialize(const string& componentName, const json::utility::objectSmartPointer<json::utility::jsonObject>& description, BaseComposite* parent) const
		{
			using json::utility::objectSmartPointer;
			using json::utility::jsonObject;

			parsers::RichEditParser parser;

			parser.parse(description);

			RichEdit* result = nullptr;
			uint32_t codepage = interfaces::ISerializable::getCodepage();
			const smartPointerType<utility::BaseComponentCreator>& creator = GUIFramework::get().getCreators().at(utility::getTypeHash<RichEdit>());
			utility::AdditionalCreationData<RichEdit> creationData(parser.callbacks, parser.isMultiLine, parser.limitTextCount);

			result = static_cast<RichEdit*>(creator->create(utility::to_wstring(componentName, codepage), parser.settings, creationData.getData(), parent));

			result->setBackgroundColor(parser.backgroundColor[0], parser.backgroundColor[1], parser.backgroundColor[2]);

			result->setTextColor(parser.textColor[0], parser.textColor[1], parser.textColor[2]);

			return result;
		}
	}
}
