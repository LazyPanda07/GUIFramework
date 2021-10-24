#include "DropDownComboBoxDeserializer.h"

#include "Deserialization/Parsers/ComboBoxParser.h"

using namespace std;

namespace gui_framework
{
	namespace deserializers
	{
		BaseComponent* DropDownComboBoxDeserializer::deserialize(const std::string& componentName, const json::utility::objectSmartPointer<json::utility::jsonObject>& description, BaseComposite* parent) const
		{
			using json::utility::objectSmartPointer;
			using json::utility::jsonObject;

			parsers::ComboBoxParser parser;

			parser.parse(description);

			DropDownComboBox* result = nullptr;
			uint32_t codepage = interfaces::ISerializable::getCodepage();
			const smartPointerType<utility::BaseComponentCreator>& creator = GUIFramework::get().getCreators().at(utility::getTypeHash<DropDownComboBox>());
			utility::AdditionalCreationData<DropDownComboBox> creationData(parser.values, parser.functionName, parser.moduleName);

			result = static_cast<DropDownComboBox*>(creator->create(utility::to_wstring(componentName, codepage), parser.settings, creationData.getData(), parent));

			return result;
		}
	}
}
