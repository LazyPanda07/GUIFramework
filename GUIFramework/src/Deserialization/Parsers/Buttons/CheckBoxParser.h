#pragma once

#include "ButtonParser.h"

namespace gui_framework
{
	namespace parsers
	{
		/// @brief Parse CheckBox specific properties
		struct GUI_FRAMEWORK_API CheckBoxParser : public ButtonParser
		{
			std::string onCheckFunctionName;
			std::string onCheckModuleName;
			std::string onClearFunctionName;
			std::string onClearModuleName;

		public:
			CheckBoxParser() = default;

			void parse(const json::utility::jsonObject& description) override;

			~CheckBoxParser() = default;
		};
	}
}
