#pragma once

#include "headers.h"
#include "BaseComponentCreator.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief ImageButton creator
		class GUI_FRAMEWORK_API ImageButtonCreator : public BaseComponentCreator
		{
		public:
			ImageButtonCreator() = default;
			
			BaseComponent* create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComponent* parent) override;

			~ImageButtonCreator() = default;
		};
	}
}
