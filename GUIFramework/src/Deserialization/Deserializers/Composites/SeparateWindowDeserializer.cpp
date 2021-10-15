#include "headers.h"
#include "SeparateWindowDeserializer.h"

#include "Deserialization/Deserializers/Parsers/BaseCompositeParser.h"

using namespace std;

namespace gui_framework
{
	namespace deserializers
	{
		BaseComponent* SeparateWindowDeserializer::deserialize(const string& componentName, const json::utility::objectSmartPointer<json::utility::jsonObject>& description, BaseComposite* parent) const
		{
			using json::utility::objectSmartPointer;
			using json::utility::jsonObject;

			parsers::BaseCompositeParser parser;

			parser.parse(description);

			SeparateWindow* result = nullptr;
			uint32_t codepage = interfaces::ISerializable::getCodepage();
			const unique_ptr<utility::BaseComponentCreator>& creator = GUIFramework::get().getCreators().at(utility::getTypeHash<SeparateWindow>());
			utility::AdditionalCreationData<SeparateWindow> creationData(parser.className, parser.windowFunctionName);
			const auto& children = description->getArray("children");

			result = static_cast<SeparateWindow*>(creator->create(utility::to_wstring(componentName, codepage), parser.settings, creationData.getData(), nullptr));

			result->setBackgroundColor(parser.backgroundColor[0], parser.backgroundColor[1], parser.backgroundColor[2]);

			result->setTextColor(parser.textColor[0], parser.textColor[1], parser.textColor[2]);

			result->setExitMode(parser.mode);

			result->setLargeIcon(parser.pathToLargeIcon);

			result->setSmallIcon(parser.pathToSmallIcon);

			for (const auto& i : children)
			{
				const auto& [componentName, data] = get<objectSmartPointer<jsonObject>>(i->data.front().second)->data.front();
				const auto& description = get<objectSmartPointer<jsonObject>>(data);

				const unique_ptr<interfaces::IDeserializer>& deserializer = GUIFramework::get().getDeserializers().at(description->getUnsignedInt("hash"));

				deserializer->deserialize(componentName, description, result);
			}

			return result;
		}
	}
}
