#include "headers.h"
#include "GroupBoxDeserializer.h"

#include "Deserialization/Parsers/GroupBoxParser.h"

using namespace std;

namespace gui_framework
{
	namespace deserializers
	{
		BaseComponent* GroupBoxDeserializer::deserialize(const string& componentName, const json::utility::objectSmartPointer<json::utility::jsonObject>& description, BaseComposite* parent) const
		{
			using json::utility::objectSmartPointer;
			using json::utility::jsonObject;

			parsers::GroupBoxParser parser;

			parser.parse(description);

			GroupBox* result = nullptr;
			uint32_t codepage = interfaces::ISerializable::getCodepage();
			const smartPointerType<utility::BaseComponentCreator>& creator = GUIFramework::get().getCreators().at(utility::getTypeHash<GroupBox>());
			utility::AdditionalCreationData<GroupBox> creationData(parser.className, parser.windowFunctionName, parser.data);

			result = static_cast<GroupBox*>(creator->create(utility::to_wstring(componentName, codepage), parser.settings, creationData.getData(), parent));

			result->setBackgroundColor(parser.backgroundColor[0], parser.backgroundColor[1], parser.backgroundColor[2]);

			result->setTextColor(parser.textColor[0], parser.textColor[1], parser.textColor[2]);

			result->setStyles(parser.styles);

			return result;
		}
	}
}
