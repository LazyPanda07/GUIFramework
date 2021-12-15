#include "ListBoxDeserializer.h"

#include "Deserialization/Parsers/ListBoxParser.h"
#include "GUIFramework.h"
#include "Utility/AdditionalCreationData/ListBoxAdditionalCreationData.h"

using namespace std;

namespace gui_framework
{
	namespace deserializers
	{
		BaseComponent* ListBoxDeserializer::deserialize(const std::string& componentName, const json::utility::objectSmartPointer<json::utility::jsonObject>& description, BaseComposite* parent) const
		{
			using json::utility::objectSmartPointer;
			using json::utility::jsonObject;

			parsers::ListBoxParser parser;

			parser.parse(description);

			ListBox* result = nullptr;
			uint32_t codepage = interfaces::ISerializable::getCodepage();
			const smartPointerType<utility::BaseComponentCreator>& creator = GUIFramework::get().getCreators().at(utility::getTypeHash<ListBox>());
			utility::AdditionalCreationData<ListBox> creationData(parser.values);

			result = static_cast<ListBox*>(creator->create(utility::to_wstring(componentName, codepage), parser.settings, creationData.getData(), parent));

			return result;
		}
	}
}
