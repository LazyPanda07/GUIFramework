#include "StaticControlDeserializer.h"

#include "Deserialization/Parsers/BaseComponentParser.h"
#include "GUIFramework.h"
#include "Utility/AdditionalCreationData/StaticControlAdditionalCreationData.h"

using namespace std;

namespace gui_framework
{
	namespace deserializers
	{
		BaseComponent* StaticControlDeserializer::deserialize(const string& componentName, const json::utility::jsonObject& description, BaseComposite* parent) const
		{
			using json::utility::jsonObject;

			parsers::BaseComponentParser parser;

			parser.parse(description);

			StaticControl* result = nullptr;
			uint32_t codepage = interfaces::ISerializable::getCodepage();
			const smartPointerType<utility::BaseComponentCreator>& creator = GUIFramework::get().getCreators().at(utility::getTypeHash<StaticControl>());
			utility::AdditionalCreationData<StaticControl> creationData(utility::to_wstring(description.getString("text"), codepage));

			result = static_cast<StaticControl*>(creator->create(utility::to_wstring(componentName, codepage), parser.settings, creationData.getData(), parent));

			result->setBackgroundColor(parser.backgroundColor[0], parser.backgroundColor[1], parser.backgroundColor[2]);

			result->setTextColor(parser.textColor[0], parser.textColor[1], parser.textColor[2]);

			return result;
		}
	}
}
