#include "TextIconListViewDeserializer.h"

#include "Deserialization/Parsers/ListViews/TextIconListViewParser.h"
#include "GUIFramework.h"
#include "Utility/AdditionalCreationData/TextIconListViewAdditionalCreationData.h"

using namespace std;

namespace gui_framework
{
	namespace deserializers
	{
		BaseComponent* TextIconListViewDeserializer::deserialize(const string& componentName, const json::utility::jsonObject& description, BaseComposite* parent) const
		{
			using json::utility::jsonObject;

			parsers::TextIconListViewParser parser;

			parser.parse(description);

			TextIconListView* result = nullptr;
			uint32_t codepage = interfaces::ISerializable::getCodepage();
			const smartPointerType<utility::BaseComponentCreator>& creator = GUIFramework::get().getCreators().at(utility::getTypeHash<TextIconListView>());
			vector<pair<wstring, filesystem::path>> values;

			values.reserve(parser.values.size());

			for (size_t i = 0; i < parser.values.size(); i++)
			{
				values.emplace_back(parser.values[i], parser.icons[i]);
			}

			utility::AdditionalCreationData<TextIconListView> creationData(parser.type, values);

			result = static_cast<TextIconListView*>(creator->create(utility::to_wstring(componentName, codepage), parser.settings, creationData.getData(), parent));

			result->setBackgroundColor(parser.backgroundColor[0], parser.backgroundColor[1], parser.backgroundColor[2]);

			result->setTextColor(parser.textColor[0], parser.textColor[1], parser.textColor[2]);

			return result;
		}
	}
}
