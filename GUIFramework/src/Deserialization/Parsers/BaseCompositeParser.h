#pragma once

#include "BaseComponentParser.h"
#include "BaseComposites/BaseComposite.h"

namespace gui_framework
{
	namespace parsers
	{
		/// @brief Parse BaseComposite properties
		struct GUI_FRAMEWORK_API BaseCompositeParser : public BaseComponentParser
		{
			std::string windowFunctionName;
			BaseComposite::exitMode mode;
			std::string onDestroyFunctionName;
			std::string onDestroyFunctionModuleName;

		public:
			BaseCompositeParser();

			virtual void parse(const json::utility::objectSmartPointer<json::utility::jsonObject>& description) override;

			virtual ~BaseCompositeParser() = default;
		};
	}
}
