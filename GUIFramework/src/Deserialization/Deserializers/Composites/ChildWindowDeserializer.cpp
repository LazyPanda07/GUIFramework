#include "headers.h"
#include "ChildWindowDeserializer.h"

#include "Deserialization/Parsers/BaseCompositeParser.h"
#include "GUIFramework.h"
#include "Utility/AdditionalCreationData/ChildWindowAdditionalCreationData.h"

using namespace std;

namespace gui_framework
{
	namespace deserializers
	{
		BaseComponent* ChildWindowDeserializer::deserialize(const string& componentName, const json::utility::objectSmartPointer<json::utility::jsonObject>& description, BaseComposite* parent) const
		{
			using json::utility::objectSmartPointer;
			using json::utility::jsonObject;

			parsers::BaseCompositeParser parser;

			parser.parse(description);

			ChildWindow* result = nullptr;
			uint32_t codepage = interfaces::ISerializable::getCodepage();
			const smartPointerType<utility::BaseComponentCreator>& creator = GUIFramework::get().getCreators().at(utility::getTypeHash<ChildWindow>());
			utility::AdditionalCreationData<ChildWindow> creationData(parser.className, parser.windowFunctionName);
			
			result = static_cast<ChildWindow*>(creator->create(utility::to_wstring(componentName, codepage), parser.settings, creationData.getData(), parent));

			result->setBackgroundColor(parser.backgroundColor[0], parser.backgroundColor[1], parser.backgroundColor[2]);

			result->setTextColor(parser.textColor[0], parser.textColor[1], parser.textColor[2]);

			result->setExitMode(parser.mode);

			if (parser.onDestroyFunctionName.size())
			{
				result->setOnDestroy(parser.onDestroyFunctionName, parser.onDestroyFunctionModuleName);
			}

			if (description->contains("children", json::utility::variantTypeEnum::jJSONArray))
			{
				const auto& children = description->getArray("children");

				for (const auto& i : children)
				{
					const auto& [componentName, data] = get<objectSmartPointer<jsonObject>>(i->data.front().second)->data.front();
					const auto& description = get<objectSmartPointer<jsonObject>>(data);

					const smartPointerType<interfaces::IDeserializer>& deserializer = GUIFramework::get().getDeserializers().at(description->getUnsignedInt("hash"));

					deserializer->deserialize(componentName, description, result);
				}
			}

			return result;
		}
	}
}
