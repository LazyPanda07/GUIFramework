#pragma once

#include "BaseCompositeParser.h"

namespace gui_framework
{
	namespace parsers
	{
		/// @brief Parse SeparateWindow specific properties
		struct GUI_FRAMEWORK_API SeparateWindowParser : public BaseCompositeParser
		{
			std::string pathToLargeIcon;
			std::string pathToSmallIcon;
			std::string onCloseFunctionName;
			std::string onCloseFunctionModuleName;

		public:
			SeparateWindowParser() = default;

			void parse(const json::utility::objectSmartPointer<json::utility::jsonObject>& description) override;

			~SeparateWindowParser() = default;
		};
	}
}
