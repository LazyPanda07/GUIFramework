#pragma once

#include "Utility/Creators/BaseComponentCreator.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief RichEdit creator
		class GUI_FRAMEWORK_API RichEditCreator : public BaseComponentCreator
		{
		public:
			RichEditCreator() = default;

			BaseComponent* create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComposite* parent) override;

			~RichEditCreator() = default;
		};
	}
}
