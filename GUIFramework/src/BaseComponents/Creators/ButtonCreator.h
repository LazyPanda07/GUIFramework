#pragma once

#include "BaseComponentCreator.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief gui_framework::Button creator
		class GUI_FRAMEWORK_API ButtonCreator : public BaseComponentCreator
		{
		public:
			ButtonCreator() = default;

			BaseComponent* create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComponent* parent) override;

			~ButtonCreator() = default;
		};
	}
}
