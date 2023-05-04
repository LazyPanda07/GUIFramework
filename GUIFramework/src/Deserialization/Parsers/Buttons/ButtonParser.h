#pragma once

#include "Deserialization/Parsers/BaseComponentParser.h"

namespace gui_framework
{
	namespace parsers
	{
		/// @brief Parse Button specific properties
		struct GUI_FRAMEWORK_API ButtonParser : public BaseComponentParser
		{
			std::wstring text;
			std::string onClickFunctionName;
			std::string onClickFunctionModule;
			std::string pathToModule;

		public:
			ButtonParser() = default;

			void parse(const json::utility::jsonObject& description) override;

			~ButtonParser() = default;
		};
	}
}
