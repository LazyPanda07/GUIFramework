#include "HorizontalTrackbarControlDeserializer.h"

#include "Deserialization/Parsers/TrackbarControlParser.h"
#include "Components/Trackbars/HorizontalTrackbarControl.h"
#include "GUIFramework.h"
#include "Utility/AdditionalCreationData/TrackbarControlAdditionalCreationData.h"

using namespace std;

namespace gui_framework
{
	namespace deserializers
	{
		BaseComponent* HorizontalTrackbarControlDeserializer::deserialize(const std::string & componentName, const json::utility::objectSmartPointer<json::utility::jsonObject>&description, BaseComposite * parent) const
		{
			using json::utility::objectSmartPointer;
			using json::utility::jsonObject;

			parsers::TrackbarControlParser parser;

			parser.parse(description);

			HorizontalTrackbarControl* result = nullptr;
			uint32_t codepage = interfaces::ISerializable::getCodepage();
			const smartPointerType<utility::BaseComponentCreator>& creator = GUIFramework::get().getCreators().at(utility::getTypeHash<HorizontalTrackbarControl>());
			utility::AdditionalCreationData<HorizontalTrackbarControl> creationData;

			result = static_cast<HorizontalTrackbarControl*>(creator->create(utility::to_wstring(componentName, codepage), parser.settings, creationData.getData(), parent));

			result->setBackgroundColor(parser.backgroundColor[0], parser.backgroundColor[1], parser.backgroundColor[2]);

			result->setMinRange(parser.minRange);

			result->setMaxRange(parser.maxRange);

			result->setSelectionStart(parser.selectionStart);

			result->setSelectionEnd(parser.selectionEnd);

			return result;
		}
	}
}
