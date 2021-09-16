#include "headers.h"
#include "SeparateWindowDeserializer.h"

#include "ChildWindowDeserializer.h"

using namespace std;

namespace gui_framework
{
	namespace deserializers
	{
		BaseComponent* SeparateWindowDeserializer::deserialize(const string& componentName, const json::utility::objectSmartPointer<json::utility::jsonObject>& description, BaseComposite* parent) const
		{
			using json::utility::objectSmartPointer;
			using json::utility::jsonObject;

			SeparateWindow* result = nullptr;
			uint32_t codepage = interfaces::ISerializable::getCodepage();
			const unique_ptr<utility::BaseComponentCreator>& creator = GUIFramework::get().getCreators().at(utility::getTypeHash<SeparateWindow>());
			utility::AdditionalCreationData<SeparateWindow> creationData(utility::to_wstring(description->getString("className"), CP_UTF8), description->getString("windowFunctionName"));
			utility::ComponentSettings settings
			(
				static_cast<int>(description->getInt("desiredX")),
				static_cast<int>(description->getInt("desiredY")),
				static_cast<uint16_t>(description->getUnsignedInt("desiredWidth")),
				static_cast<uint16_t>(description->getUnsignedInt("desiredHeight"))
			);
			const auto& backgroundColor = json::utility::JSONArrayWrapper(description->getArray("backgroundColor")).getAsInt64_tArray();
			const auto& textColor = json::utility::JSONArrayWrapper(description->getArray("textColor")).getAsInt64_tArray();;
			const auto& children = description->getArray("children");

			result = static_cast<SeparateWindow*>(creator->create(utility::to_wstring(componentName, codepage), settings, creationData.getData(), nullptr));

			result->setBackgroundColor(static_cast<uint8_t>(backgroundColor[0]), static_cast<uint8_t>(backgroundColor[1]), static_cast<uint8_t>(backgroundColor[2]));

			result->setTextColor(static_cast<uint8_t>(textColor[0]), static_cast<uint8_t>(textColor[1]), static_cast<uint8_t>(textColor[2]));

			result->setExitMode(static_cast<gui_framework::BaseComponent::exitMode>(description->getInt("exitMode")));

			if (ranges::find_if(description->data, [](const auto& value) { return value.first == "pathToLargeIcon"; }) != description->data.end())
			{
				result->setLargeIcon(description->getString("pathToLargeIcon"));
			}

			if (ranges::find_if(description->data, [](const auto& value) { return value.first == "pathToSmallIcon"; }) != description->data.end())
			{
				result->setLargeIcon(description->getString("pathToSmallIcon"));
			}

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
