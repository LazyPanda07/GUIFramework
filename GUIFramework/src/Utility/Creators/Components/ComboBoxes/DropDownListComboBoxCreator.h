#pragma once

#include "Utility/Creators/BaseComponentCreator.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief DropDownListComboBox creator
		class GUI_FRAMEWORK_API DropDownListComboBoxCreator : public BaseComponentCreator
		{
		public:
			DropDownListComboBoxCreator() = default;

			BaseComponent* create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComposite* parent) override;

			~DropDownListComboBoxCreator() = default;
		};
	}
}
