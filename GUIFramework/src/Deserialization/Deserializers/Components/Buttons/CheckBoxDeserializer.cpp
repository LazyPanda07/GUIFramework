#include "CheckBoxDeserializer.h"

#include "Deserialization/Parsers/Buttons/CheckBoxParser.h"
#include "GUIFramework.h"
#include "Utility/AdditionalCreationData/ButtonAdditionalCreationData.h"

using namespace std;

namespace gui_framework
{
	namespace deserializers
	{
		BaseComponent* CheckBoxDeserializer::deserialize(const string& componentName, const json::utility::jsonObject& description, BaseComposite* parent) const
		{
			using json::utility::jsonObject;

			parsers::CheckBoxParser parser;

			parser.parse(description);

			CheckBox* result = nullptr;
			uint32_t codepage = interfaces::ISerializable::getCodepage();
			const smartPointerType<utility::BaseComponentCreator>& creator = GUIFramework::get().getCreators().at(utility::getTypeHash<CheckBox>());
			utility::AdditionalCreationData<CheckBox> creationData
			(
				parser.text,
				parser.onCheckFunctionName,
				parser.onCheckModuleName,
				parser.onClearFunctionName,
				parser.onCheckModuleName,
				parser.onClickFunctionName,
				parser.onClickFunctionModule
			);

			result = static_cast<CheckBox*>(creator->create(utility::to_wstring(componentName, codepage), parser.settings, creationData.getData(), parent));

			result->setBackgroundColor(parser.backgroundColor[0], parser.backgroundColor[1], parser.backgroundColor[2]);

			return result;
		}
	}
}
