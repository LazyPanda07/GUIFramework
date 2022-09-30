#pragma once

#include "Utility/Creators/BaseComponentCreator.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief ImageButton creator
		class GUI_FRAMEWORK_API ImageButtonCreator : public BaseComponentCreator
		{
		public:
			ImageButtonCreator() = default;
			
			BaseComponent* create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComposite* parent) override;

			~ImageButtonCreator() = default;
		};
	}
}
