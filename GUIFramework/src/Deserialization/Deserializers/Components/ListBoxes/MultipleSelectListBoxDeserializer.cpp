#include "MultipleSelectListBoxDeserializer.h"

#include "Deserialization/Parsers/ListBoxParser.h"
#include "GUIFramework.h"
#include "Utility/AdditionalCreationData/ListBoxAdditionalCreationData.h"

using namespace std;

namespace gui_framework
{
	namespace deserializers
	{
		BaseComponent* MultipleSelectListBoxDeserializer::deserialize(const std::string& componentName, const json::utility::objectSmartPointer<json::utility::jsonObject>& description, BaseComposite* parent) const
		{
			using json::utility::objectSmartPointer;
			using json::utility::jsonObject;

			parsers::ListBoxParser parser;

			parser.parse(description);

			MultipleSelectListBox* result = nullptr;
			uint32_t codepage = interfaces::ISerializable::getCodepage();
			const smartPointerType<utility::BaseComponentCreator>& creator = GUIFramework::get().getCreators().at(utility::getTypeHash<MultipleSelectListBox>());
			utility::AdditionalCreationData<MultipleSelectListBox> creationData(parser.values);

			result = static_cast<MultipleSelectListBox*>(creator->create(utility::to_wstring(componentName, codepage), parser.settings, creationData.getData(), parent));

			return result;
		}
	}
}
