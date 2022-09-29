#pragma once

#include "core.h"
#include "Utility/Creators/BaseComponentCreator.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief GroupBox creator
		class GUI_FRAMEWORK_API GroupBoxCreator : public BaseComponentCreator
		{
		public:
			GroupBoxCreator() = default;

			BaseComponent* create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComponent* parent) override;

			~GroupBoxCreator() = default;
		};
	}
}
