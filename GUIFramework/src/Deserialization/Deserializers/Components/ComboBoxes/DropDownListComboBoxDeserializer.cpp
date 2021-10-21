#include "DropDownListComboBoxDeserializer.h"

#include "Deserialization/Parsers/ComboBoxParser.h"

using namespace std;

namespace gui_framework
{
	namespace deserializers
	{
		BaseComponent* DropDownListComboBoxDeserializer::deserialize(const std::string& componentName, const json::utility::objectSmartPointer<json::utility::jsonObject>& description, BaseComposite* parent) const
		{
			using json::utility::objectSmartPointer;
			using json::utility::jsonObject;

			parsers::ComboBoxParser parser;

			parser.parse(description);

			DropDownListComboBox* result = nullptr;
			uint32_t codepage = interfaces::ISerializable::getCodepage();
			const smartPointerType<utility::BaseComponentCreator>& creator = GUIFramework::get().getCreators().at(utility::getTypeHash<DropDownListComboBox>());
			utility::AdditionalCreationData<DropDownListComboBox> creationData(parser.values, parser.functionName, parser.moduleName);

			result = static_cast<DropDownListComboBox*>(creator->create(utility::to_wstring(componentName, codepage), parser.settings, creationData.getData(), parent));

			result->setStyles(parser.styles);

			return result;
		}
	}
}
