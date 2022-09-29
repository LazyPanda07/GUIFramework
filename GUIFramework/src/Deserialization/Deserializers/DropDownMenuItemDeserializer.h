#pragma once

#include "core.h"
#include "MenuItems/DropDownMenuItem.h"
#include "BaseComposites/StandardComposites/BaseSeparateWindow.h"

namespace gui_framework
{
	namespace deserializers
	{
		/// @brief Deserialize DropDownMenuItem from JSON
		class GUI_FRAMEWORK_API DropDownMenuItemDeserializer
		{
		private:
			BaseSeparateWindow* menuHolder;

		public:
			DropDownMenuItemDeserializer(BaseSeparateWindow* menuHolder);

			/// @brief 
			/// @param text 
			/// @param popupId 
			/// @param popupItems 
			/// @param menu 
			/// @return
			/// @exception WrongMenuTypeException 
			std::unique_ptr<DropDownMenuItem> deserializeDropDownMenuItem(const std::wstring& text, uint64_t popupId, const std::vector<json::utility::jsonObject>& popupItems, Menu& menu);

			~DropDownMenuItemDeserializer() = default;
		};
	}
}
