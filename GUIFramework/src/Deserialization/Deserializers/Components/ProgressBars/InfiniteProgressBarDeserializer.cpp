#include "InfiniteProgressBarDeserializer.h"

#include "Deserialization/Parsers/ProgressBars/InfiniteProgressBarParser.h"
#include "GUIFramework.h"
#include "Utility/AdditionalCreationData/ProgressBarAdditionalCreationData.h"

using namespace std;

namespace gui_framework
{
	namespace deserializers
	{
		BaseComponent* InfiniteProgressBarDeserializer::deserialize(const std::string& componentName, const json::utility::jsonObject& description, BaseComposite* parent) const
		{
			using json::utility::jsonObject;

			parsers::InfiniteProgressBarParser parser;

			parser.parse(description);

			InfiniteProgressBar* result = nullptr;
			uint32_t codepage = interfaces::ISerializable::getCodepage();
			const smartPointerType<utility::BaseComponentCreator>& creator = GUIFramework::get().getCreators().at(utility::getTypeHash<InfiniteProgressBar>());
			utility::AdditionalCreationData<InfiniteProgressBar> creationData(parser.animationPeriod);

			result = static_cast<InfiniteProgressBar*>(creator->create(utility::to_wstring(componentName, codepage), parser.settings, creationData.getData(), parent));

			result->setBackgroundColor(parser.backgroundColor[0], parser.backgroundColor[1], parser.backgroundColor[2]);

			return result;
		}
	}
}
