#pragma once

#include "headers.h"

namespace gui_framework
{
	namespace parsers
	{
		struct GUI_FRAMEWORK_API MenuParser
		{
			std::wstring mainMenuName;
			std::vector<json::utility::objectSmartPointer<json::utility::jsonObject>> mainMenuItems;
			std::vector<json::utility::objectSmartPointer<json::utility::jsonObject>> popupItems;

		public:
			MenuParser() = default;

			void parse(json::utility::objectSmartPointer<json::utility::jsonObject>& description);

			~MenuParser() = default;
		};
	}
}
