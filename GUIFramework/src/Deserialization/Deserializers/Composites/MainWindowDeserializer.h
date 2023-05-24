#pragma once

#include "MenuItems/MenuItem.h"
#include "MenuItems/DropDownMenuItem.h"
#include "Composites/SeparateWindow.h"
#include "GUIFramework.h"

#include "Deserialization/Parsers/MainWindowParser.h"
#include "Deserialization/Parsers/MenuParser.h"

#include "Deserialization/Deserializers/DropDownMenuItemDeserializer.h"

#include "Exceptions/Deserialization/WrongMenuTypeException.h"

namespace gui_framework
{
	namespace deserializers
	{
		/// @brief Deserialize MainWindow from JSON
		class GUI_FRAMEWORK_API MainWindowDeserializer
		{
		public:
			MainWindowDeserializer() = default;

			/**
			 * @brief MainWindow has no parent, you must manage the pointer
			 * @exception WrongMenuTypeException
			*/
			template<typename MainWindowT> requires (std::is_base_of_v<BaseMainWindow, MainWindowT>)
			void deserialize(const std::string& componentName, const json::utility::jsonObject& description, std::unique_ptr<MainWindowT>& mainWindow) const;

			~MainWindowDeserializer() = default;
		};

		template<typename MainWindowT> requires (std::is_base_of_v<BaseMainWindow, MainWindowT>)
		void MainWindowDeserializer::deserialize(const std::string& componentName, const json::utility::jsonObject& description, std::unique_ptr<MainWindowT>& mainWindow) const
		{
			using json::utility::jsonObject;

			parsers::MainWindowParser parser;
			parsers::MenuParser menuParser;
			bool hasMenus = false;
			uint32_t codepage = interfaces::ISerializable::getCodepage();

			parser.parse(description);

			if (description.contains("menuStructure", json::utility::variantTypeEnum::jJSONObject))
			{
				menuParser.parse(const_cast<jsonObject&>(description.getObject("menuStructure")));

				hasMenus = true;
			}

			mainWindow->setBackgroundColor(parser.backgroundColor[0], parser.backgroundColor[1], parser.backgroundColor[2]);

			mainWindow->setTextColor(parser.textColor[0], parser.textColor[1], parser.textColor[2]);

			if (parser.pathToLargeIcon.size())
			{
				mainWindow->setLargeIcon(parser.pathToLargeIcon);
			}

			if (parser.pathToSmallIcon.size())
			{
				mainWindow->setSmallIcon(parser.pathToSmallIcon);
			}

			if (parser.onDestroyFunctionName.size())
			{
				mainWindow->setOnDestroy(parser.onDestroyFunctionName, parser.onDestroyFunctionModuleName);
			}

			if (parser.onCloseFunctionName.size())
			{
				mainWindow->setOnDestroy(parser.onCloseFunctionName, parser.onCloseFunctionModuleName);
			}

			if (parser.trayIconResource)
			{
				mainWindow->initTray(parser.trayIconResource);
			}

			for (const auto& [text, function] : parser.items)
			{
				mainWindow->addTrayMenuItem(text, function.functionName, function.moduleName);
			}

			if (hasMenus)
			{
				auto& mainMenu = mainWindow->createMainMenu(menuParser.mainMenuName);

				for (const auto& i : menuParser.mainMenuItems)
				{
					const jsonObject& item = get<jsonObject>(i.data.front().second);

					std::wstring text = utility::to_wstring(item.getString("itemText"), codepage);
					const std::string& type = item.getString("itemType");

					if (type == standard_menu_items::menuItem)
					{
						mainMenu->addMenuItem(std::make_unique<MenuItem>(text, item.getString("functionName"), item.getString("moduleName")));
					}
					else if (type == standard_menu_items::dropDownMenuItem)
					{
						uint64_t popupId = item.getUnsignedInt("popupId");
						Menu* popupMenu = nullptr;

						for (const auto& j : menuParser.popupItems)
						{
							const jsonObject& popupItem = get<jsonObject>(j.data.front().second);

							if (popupItem.getUnsignedInt("menuId") == popupId)
							{
								popupMenu = &mainWindow->addPopupMenu(utility::to_wstring(popupItem.getString("menuName"), codepage));
							}
						}

						if (popupMenu)
						{
							mainMenu->addMenuItem(DropDownMenuItemDeserializer(mainWindow).deserializeDropDownMenuItem(text, popupId, menuParser.popupItems, *popupMenu));
						}
					}
					else
					{
						throw exceptions::deserialization::WrongMenuTypeException(type, __FILE__, __FUNCTION__, __LINE__);
					}
				}
			}

			if (description.contains("hotkeys", json::utility::variantTypeEnum::jJSONArray))
			{
				GUIFramework::get().deserializeHotkeys(description);
			}

			if (description.contains("children", json::utility::variantTypeEnum::jJSONArray))
			{
				const auto& children = description.getArray("children");

				for (const auto& i : children)
				{
					const auto& [componentName, data] = get<jsonObject>(i.data.front().second).data.front();
					const auto& description = get<jsonObject>(data);

					const smartPointerType<interfaces::IDeserializer>& deserializer = GUIFramework::get().getDeserializers().at(description.getUnsignedInt("hash"));

					deserializer->deserialize(componentName, description, mainWindow);
				}
			}
		}
	}
}
