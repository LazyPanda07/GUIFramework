#include "ProgressBarDeserializer.h"

#include "Deserialization/Parsers/ProgressBars/ProgressBarParser.h"

using namespace std;

namespace gui_framework
{
	namespace deserializers
	{
		BaseComponent* ProgressBarDeserializer::deserialize(const std::string& componentName, const json::utility::objectSmartPointer<json::utility::jsonObject>& description, BaseComposite* parent) const
		{
			using json::utility::objectSmartPointer;
			using json::utility::jsonObject;

			parsers::ProgressBarParser parser;

			parser.parse(description);

			ProgressBar* result = nullptr;
			uint32_t codepage = interfaces::ISerializable::getCodepage();
			const smartPointerType<utility::BaseComponentCreator>& creator = GUIFramework::get().getCreators().at(utility::getTypeHash<ProgressBar>());
			utility::AdditionalCreationData<ProgressBar> creationData(parser.minRange, parser.maxRange, parser.updateStep);

			result = static_cast<ProgressBar*>(creator->create(utility::to_wstring(componentName, codepage), parser.settings, creationData.getData(), parent));

			result->setBackgroundColor(parser.backgroundColor[0], parser.backgroundColor[1], parser.backgroundColor[2]);

			result->setStyles(parser.styles);

			return result;
		}
	}
}
