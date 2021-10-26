#pragma once

#include "BaseComponentParser.h"

namespace gui_framework
{
	namespace parsers
	{
		/// @brief Parse BaseComposite properties
		struct GUI_FRAMEWORK_API BaseCompositeParser : public BaseComponentParser
		{
			std::string windowFunctionName;
			BaseComposite::exitMode mode;
			std::string pathToLargeIcon;
			std::string pathToSmallIcon;
			std::string onDestroyFunctionName;
			std::string onDestroyFunctionModuleName;

		public:
			BaseCompositeParser() = default;

			virtual void parse(const json::utility::objectSmartPointer<json::utility::jsonObject>& description) override;

			virtual ~BaseCompositeParser() = default;
		};
	}
}
