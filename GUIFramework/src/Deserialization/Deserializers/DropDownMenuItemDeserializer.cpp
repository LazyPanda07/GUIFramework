#include "DropDownMenuItemDeserializer.h"

#include "MenuItems/MenuItem.h"
#include "Utility/Utility.h"
#include "BaseComposites/StandardComposites/BaseSeparateWindow.h"

#include "Exceptions/Deserialization/WrongMenuTypeException.h"

using namespace std;

namespace gui_framework
{
	namespace deserializers
	{
		DropDownMenuItemDeserializer::DropDownMenuItemDeserializer(BaseSeparateWindow* menuHolder) :
			menuHolder(menuHolder)
		{

		}

		unique_ptr<DropDownMenuItem> DropDownMenuItemDeserializer::deserializeDropDownMenuItem(const wstring& text, uint64_t popupId, const std::vector<json::utility::jsonObject>& popupItems, Menu& menu)
		{
			using json::utility::jsonObject;

			uint32_t codepage = interfaces::ISerializable::getCodepage();

			for (const auto& i : popupItems)
			{
				const jsonObject& item = get<jsonObject>(i.data.front().second);

				uint64_t menuId = item.getUnsignedInt("menuId");

				if (menuId != popupId)
				{
					continue;
				}

				wstring name = utility::to_wstring(item.getString("menuName"), codepage);
				const vector<jsonObject>& dropDownItems = item.getArray("items");

				for (const auto& j : dropDownItems)
				{
					const jsonObject& dropDownItem = get<jsonObject>(j.data.front().second);

					wstring text = utility::to_wstring(dropDownItem.getString("itemText"), codepage);

					const string& type = dropDownItem.getString("itemType");

					if (type == standard_menu_items::menuItem)
					{
						menu.addMenuItem(make_unique<MenuItem>(text, dropDownItem.getString("functionName"), dropDownItem.getString("moduleName")));
					}
					else if (type == standard_menu_items::dropDownMenuItem)
					{
						Menu* popupMenu = nullptr;
						uint64_t insidePopupId = dropDownItem.getUnsignedInt("popupId");

						for (const auto& j : popupItems)
						{
							const jsonObject& popupItem = get<jsonObject>(j.data.front().second);

							if (popupItem.getUnsignedInt("menuId") == insidePopupId)
							{
								popupMenu = &menuHolder->addPopupMenu(utility::to_wstring(popupItem.getString("menuName"), codepage));
							}
						}

						if (popupMenu)
						{
							menu.addMenuItem(DropDownMenuItemDeserializer(menuHolder).deserializeDropDownMenuItem(text, insidePopupId, popupItems, *popupMenu));
						}
					}
					else
					{
						throw exceptions::deserialization::WrongMenuTypeException(type, __FILE__, __FUNCTION__, __LINE__);
					}
				}
			}

			return make_unique<DropDownMenuItem>(text, menu.getHandle());
		}
	}
}
