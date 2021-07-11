#pragma once

#include "BaseComponentCreator.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief DropDownListComboBox creator
		class GUI_FRAMEWORK_API DropDownListComboBoxCreator : public BaseComponentCreator
		{
		public:
			DropDownListComboBoxCreator() = default;

			BaseComponent* create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComponent* parent) override;

			~DropDownListComboBoxCreator() = default;
		};
	}
}
