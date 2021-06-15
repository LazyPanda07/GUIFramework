#pragma once

#include "BaseComponentCreator.h"

namespace gui_framework
{
	namespace utility
	{
		class SimpleComboBoxCreator : public BaseComponentCreator
		{
		public:
			SimpleComboBoxCreator() = default;

			BaseComponent* create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComponent* parent) override;

			~SimpleComboBoxCreator() = default;
		};
	}
}
