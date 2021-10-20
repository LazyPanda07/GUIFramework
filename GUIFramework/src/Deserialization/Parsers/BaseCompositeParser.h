#pragma once

#include "BaseComponentParser.h"

namespace gui_framework
{
	namespace parsers
	{
		struct GUI_FRAMEWORK_API BaseCompositeParser : public BaseComponentParser
		{
			std::string windowFunctionName;
			BaseComposite::exitMode mode;
			std::string pathToLargeIcon;
			std::string pathToSmallIcon;

		public:
			BaseCompositeParser() = default;

			virtual void parse(const json::utility::objectSmartPointer<json::utility::jsonObject>& description) override;

			virtual ~BaseCompositeParser() = default;
		};
	}
}
