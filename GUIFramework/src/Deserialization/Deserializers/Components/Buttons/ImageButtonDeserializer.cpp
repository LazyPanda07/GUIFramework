#include "ImageButtonDeserializer.h"

#include "Deserialization/Deserializers/Parsers/ImageButtonParser.h"

using namespace std;

namespace gui_framework
{
	namespace deserializers
	{
		BaseComponent* ImageButtonDeserializer::deserialize(const string& componentName, const json::utility::objectSmartPointer<json::utility::jsonObject>& description, BaseComposite* parent) const
		{
			using json::utility::objectSmartPointer;
			using json::utility::jsonObject;

			parsers::ImageButtonParser parser;

			parser.parse(description);

			ImageButton* result = nullptr;
			uint32_t codepage = interfaces::ISerializable::getCodepage();
			const unique_ptr<utility::BaseComponentCreator>& creator = GUIFramework::get().getCreators().at(utility::getTypeHash<ImageButton>());
			utility::AdditionalCreationData<ImageButton> creationData(parser.text, parser.pathToImage, parser.imageWidth, parser.imageHeight, parser.type, parser.onClickFunctionName, parser.onClickFunctionModule);

			result = static_cast<ImageButton*>(creator->create(utility::to_wstring(componentName, codepage), parser.settings, creationData.getData(), parent));

			result->setBackgroundColor(parser.backgroundColor[0], parser.backgroundColor[1], parser.backgroundColor[2]);

			result->setStyles(parser.styles);

			return result;
		}
	}
}
