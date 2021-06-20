#pragma once

#include "BaseComponentCreator.h"

namespace gui_framework
{
	namespace utility
	{
		class GUI_FRAMEWORK_API TabControlCreator : public BaseComponentCreator
		{
		public:
			TabControlCreator() = default;

			BaseComponent* create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComponent* parent) override;

			~TabControlCreator() = default;
		};
	}
}
