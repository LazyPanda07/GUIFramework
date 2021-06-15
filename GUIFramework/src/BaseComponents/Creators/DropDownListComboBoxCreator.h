#pragma once

#include "BaseComponentCreator.h"

namespace gui_framework
{
	namespace utility
	{
		class DropDownListComboBoxCreator : public BaseComponentCreator
		{
		public:
			DropDownListComboBoxCreator() = default;

			BaseComponent* create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComponent* parent) override;

			~DropDownListComboBoxCreator() = default;
		};
	}
}
