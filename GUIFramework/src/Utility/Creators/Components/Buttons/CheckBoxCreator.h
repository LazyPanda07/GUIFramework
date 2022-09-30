#pragma once

#include "Utility/Creators/BaseComponentCreator.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief CheckBox creator
		class GUI_FRAMEWORK_API CheckBoxCreator : public BaseComponentCreator
		{
		public:
			CheckBoxCreator() = default;

			BaseComponent* create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComposite* parent) override;

			~CheckBoxCreator() = default;
		};
	}
}
