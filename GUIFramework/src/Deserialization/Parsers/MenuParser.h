#pragma once

#include "Core.h"

namespace gui_framework
{
	namespace parsers
	{
		struct GUI_FRAMEWORK_API MenuParser
		{
			std::wstring mainMenuName;
			std::vector<json::utility::jsonObject> mainMenuItems;
			std::vector<json::utility::jsonObject> popupItems;

		public:
			MenuParser() = default;

			void parse(json::utility::jsonObject& description);

			~MenuParser() = default;
		};
	}
}
