#include "SimpleComboBoxDeserializer.h"

#include "Deserialization/Parsers/ComboBoxParser.h"

using namespace std;

namespace gui_framework
{
	namespace deserializers
	{
		BaseComponent* SimpleComboBoxDeserializer::deserialize(const std::string& componentName, const json::utility::objectSmartPointer<json::utility::jsonObject>& description, BaseComposite* parent) const
		{
			using json::utility::objectSmartPointer;
			using json::utility::jsonObject;

			parsers::ComboBoxParser parser;

			parser.parse(description);

			SimpleComboBox* result = nullptr;
			uint32_t codepage = interfaces::ISerializable::getCodepage();
			const unique_ptr<utility::BaseComponentCreator>& creator = GUIFramework::get().getCreators().at(utility::getTypeHash<SimpleComboBox>());
			utility::AdditionalCreationData<SimpleComboBox> creationData(parser.values, parser.functionName, parser.moduleName);

			result = static_cast<SimpleComboBox*>(creator->create(utility::to_wstring(componentName, codepage), parser.settings, creationData.getData(), parent));

			result->setStyles(parser.styles);

			return result;
		}
	}
}