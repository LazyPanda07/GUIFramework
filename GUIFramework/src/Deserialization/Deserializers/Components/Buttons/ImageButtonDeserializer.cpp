#include "ImageButtonDeserializer.h"

#include "Deserialization/Parsers/Buttons/ImageButtonParser.h"
#include "GUIFramework.h"
#include "Utility/AdditionalCreationData/ButtonAdditionalCreationData.h"

using namespace std;

namespace gui_framework
{
	namespace deserializers
	{
		BaseComponent* ImageButtonDeserializer::deserialize(const string& componentName, const json::utility::jsonObject& description, BaseComposite* parent) const
		{
			using json::utility::jsonObject;

			parsers::ImageButtonParser parser;

			parser.parse(description);

			ImageButton* result = nullptr;
			uint32_t codepage = interfaces::ISerializable::getCodepage();
			const smartPointerType<utility::BaseComponentCreator>& creator = GUIFramework::get().getCreators().at(utility::getTypeHash<ImageButton>());
			utility::AdditionalCreationData<ImageButton> creationData(parser.text, parser.pathToImage, parser.imageWidth, parser.imageHeight, parser.type, parser.onClickFunctionName, parser.onClickFunctionModule);

			result = static_cast<ImageButton*>(creator->create(utility::to_wstring(componentName, codepage), parser.settings, creationData.getData(), parent));

			result->setBackgroundColor(parser.backgroundColor[0], parser.backgroundColor[1], parser.backgroundColor[2]);

			return result;
		}
	}
}
