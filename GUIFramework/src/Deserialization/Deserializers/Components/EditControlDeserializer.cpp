#include "EditControlDeserializer.h"

#include "Deserialization/Parsers/BaseComponentParser.h"
#include "GUIFramework.h"
#include "Utility/AdditionalCreationData/EditControlAdditionalCreationData.h"

using namespace std;

namespace gui_framework
{
	namespace deserializers
	{
		BaseComponent* EditControlDeserializer::deserialize(const string& componentName, const json::utility::jsonObject& description, BaseComposite* parent) const
		{
			using json::utility::jsonObject;

			parsers::BaseComponentParser parser;

			parser.parse(description);

			EditControl* result = nullptr;
			uint32_t codepage = interfaces::ISerializable::getCodepage();
			const smartPointerType<utility::BaseComponentCreator>& creator = GUIFramework::get().getCreators().at(utility::getTypeHash<EditControl>());

			result = static_cast<EditControl*>(creator->create(utility::to_wstring(componentName, codepage), parser.settings, nullptr, parent));

			result->setBackgroundColor(parser.backgroundColor[0], parser.backgroundColor[1], parser.backgroundColor[2]);

			result->setTextColor(parser.textColor[0], parser.textColor[1], parser.textColor[2]);

			result->setPlaceholder(utility::to_wstring(description.getString("placeholder"), codepage));

			return result;
		}
	}
}
