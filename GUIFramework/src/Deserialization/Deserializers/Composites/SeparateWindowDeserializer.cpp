#include "headers.h"
#include "SeparateWindowDeserializer.h"

#include "MenuItems/MenuItem.h"
#include "MenuItems/DropDownMenuItem.h"

#include "Deserialization/Parsers/BaseCompositeParser.h"
#include "Deserialization/Parsers/MenuParser.h"

#include "Deserialization/Deserializers/DropDownMenuItemDeserializer.h"

#include "Exceptions/Deserialization/WrongMenuTypeException.h"

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
			parsers::MenuParser menuParser;
			bool hasMenus = false;

			parser.parse(description);

			if (description->contains("menuStructure", json::utility::variantTypeEnum::jJSONObject))
			{
				menuParser.parse(const_cast<objectSmartPointer<jsonObject>&>(description->getObject("menuStructure")));

				hasMenus = true;
			}

			SeparateWindow* result = nullptr;
			uint32_t codepage = interfaces::ISerializable::getCodepage();
			const smartPointerType<utility::BaseComponentCreator>& creator = GUIFramework::get().getCreators().at(utility::getTypeHash<SeparateWindow>());
			utility::AdditionalCreationData<SeparateWindow> creationData(parser.className, parser.windowFunctionName);
			
			result = static_cast<SeparateWindow*>(creator->create(utility::to_wstring(componentName, codepage), parser.settings, creationData.getData(), nullptr));

			result->setBackgroundColor(parser.backgroundColor[0], parser.backgroundColor[1], parser.backgroundColor[2]);

			result->setTextColor(parser.textColor[0], parser.textColor[1], parser.textColor[2]);

			result->setExitMode(parser.mode);

			if (parser.pathToLargeIcon.size())
			{
				result->setLargeIcon(parser.pathToLargeIcon);
			}

			if (parser.pathToSmallIcon.size())
			{
				result->setSmallIcon(parser.pathToSmallIcon);
			}

			if (hasMenus)
			{
				auto& mainMenu = result->createMainMenu(menuParser.mainMenuName);

				for (const auto& i : menuParser.mainMenuItems)
				{
					const objectSmartPointer<jsonObject>& item = get<objectSmartPointer<jsonObject>>(i->data.front().second);

					wstring text = utility::to_wstring(item->getString("itemText"), codepage);
					const string& type = item->getString("itemType");

					if (type == standard_menu_items::menuItem)
					{
						mainMenu->addMenuItem(make_unique<MenuItem>(text, item->getString("functionName"), item->getString("moduleName")));
					}
					else if (type == standard_menu_items::dropDownMenuItem)
					{
						uint64_t popupId = item->getUnsignedInt("popupId");
						Menu* popupMenu = nullptr;

						for (const auto& j : menuParser.popupItems)
						{
							const objectSmartPointer<jsonObject>& popupItem = get<objectSmartPointer<jsonObject>>(j->data.front().second);

							if (popupItem->getUnsignedInt("menuId") == popupId)
							{
								popupMenu = &result->addPopupMenu(utility::to_wstring(popupItem->getString("menuName"), codepage));
							}
						}

						if (popupMenu)
						{
							mainMenu->addMenuItem(DropDownMenuItemDeserializer(result).deserializeDropDownMenuItem(text, popupId, menuParser.popupItems, *popupMenu));
						}
					}
					else
					{
						throw exceptions::deserialization::WrongMenuTypeException(type);
					}
				}
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
