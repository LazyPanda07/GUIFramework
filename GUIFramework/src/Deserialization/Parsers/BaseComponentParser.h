#pragma once

#include "headers.h"
#include "Utility/ComponentSettings.h"

namespace gui_framework
{
	namespace parsers
	{
		/// @brief Parse BaseComponent properties
		struct GUI_FRAMEWORK_API BaseComponentParser
		{
			std::wstring className;
			utility::ComponentSettings settings;
			std::array<uint8_t, 3> backgroundColor;
			std::array<uint8_t, 3> textColor;

		public:
			BaseComponentParser();

			virtual void parse(const json::utility::objectSmartPointer<json::utility::jsonObject>& description);

			virtual ~BaseComponentParser() = default;
		};
	}
}
