#pragma once

#include "BaseComponentCreator.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief gui_framework::Button creator
		class GUI_FRAMEWORK_API CheckBoxCreator : public BaseComponentCreator
		{
		public:
			CheckBoxCreator() = default;

			BaseComponent* create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComponent* parent) override;

			~CheckBoxCreator() = default;
		};
	}
}
