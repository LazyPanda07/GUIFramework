#pragma once

#include "Utility/Creators/BaseComponentCreator.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief DropDownComboBox creator
		class GUI_FRAMEWORK_API DropDownComboBoxCreator : public BaseComponentCreator
		{
		public:
			DropDownComboBoxCreator() = default;

			BaseComponent* create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComposite* parent) override;

			~DropDownComboBoxCreator() = default;
		};
	}
}
