#pragma once

#include "headers.h"
#include "MenuItems/DropDownMenuItem.h"

namespace gui_framework
{
	namespace deserializers
	{
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
			std::unique_ptr<DropDownMenuItem> deserializeDropDownMenuItem(const std::wstring& text, uint64_t popupId, const std::vector<json::utility::objectSmartPointer<json::utility::jsonObject>>& popupItems, Menu& menu);

			~DropDownMenuItemDeserializer() = default;
		};
	}
}
