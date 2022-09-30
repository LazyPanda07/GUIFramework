#pragma once

#include "Utility/Creators/BaseComponentCreator.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief SimpleComboBox creator
		class GUI_FRAMEWORK_API SimpleComboBoxCreator : public BaseComponentCreator
		{
		public:
			SimpleComboBoxCreator() = default;

			BaseComponent* create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComposite* parent) override;

			~SimpleComboBoxCreator() = default;
		};
	}
}
