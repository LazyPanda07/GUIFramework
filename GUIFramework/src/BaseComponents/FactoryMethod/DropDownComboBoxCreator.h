#pragma once

#include "BaseComponentCreator.h"

namespace gui_framework
{
	namespace utility
	{
		class DropDownComboBoxCreator : public BaseComponentCreator
		{
		public:
			DropDownComboBoxCreator() = default;

			BaseComponent* create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComponent* parent) override;

			~DropDownComboBoxCreator() = default;
		};
	}
}
