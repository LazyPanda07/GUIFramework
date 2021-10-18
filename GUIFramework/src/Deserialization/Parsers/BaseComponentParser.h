#pragma once

#include "headers.h"

namespace gui_framework
{
	namespace parsers
	{
		struct GUI_FRAMEWORK_API BaseComponentParser
		{
			std::wstring className;
			utility::ComponentSettings settings;
			std::array<uint8_t, 3> backgroundColor;
			std::array<uint8_t, 3> textColor;
			BaseComponent::exitMode mode;
			interfaces::IStyles styles;

		public:
			BaseComponentParser() = default;

			virtual void parse(const json::utility::objectSmartPointer<json::utility::jsonObject>& description);

			virtual ~BaseComponentParser() = default;
		};
	}
}
