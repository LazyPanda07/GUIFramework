#pragma once

#include "Utility/Creators/BaseComponentCreator.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief TabControl creator
		class GUI_FRAMEWORK_API TabControlCreator : public BaseComponentCreator
		{
		public:
			TabControlCreator() = default;

			BaseComponent* create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComposite* parent) override;

			~TabControlCreator() = default;
		};
	}
}
