#include "TabControlDeserializer.h"

#include "Deserialization/Parsers/TabControlParser.h"

using namespace std;

namespace gui_framework
{
	namespace deserializers
	{
		BaseComponent* TabControlDeserializer::deserialize(const std::string& componentName, const json::utility::objectSmartPointer<json::utility::jsonObject>& description, BaseComposite* parent) const
		{
			using json::utility::objectSmartPointer;
			using json::utility::jsonObject;

			parsers::TabControlParser parser;

			parser.parse(description);

			TabControl* result = nullptr;
			uint32_t codepage = interfaces::ISerializable::getCodepage();
			const unique_ptr<utility::BaseComponentCreator>& creator = GUIFramework::get().getCreators().at(utility::getTypeHash<TabControl>());
			utility::AdditionalCreationData<TabControl> creationData(parser.tabs, parser.imagesWidth, parser.imagesHeight);

			result = static_cast<TabControl*>(creator->create(utility::to_wstring(componentName, codepage), parser.settings, creationData.getData(), parent));

			result->setStyles(parser.styles);

			return result;
		}
	}
}
