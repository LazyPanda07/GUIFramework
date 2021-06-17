#pragma once

#include "BaseComponentCreator.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief gui_framework::StaticControl creator
		class GUI_FRAMEWORK_API StaticControlCreator : public BaseComponentCreator
		{
		public:
			StaticControlCreator() = default;

			BaseComponent* create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComponent* parent) override;

			~StaticControlCreator() = default;
		};
	}
}
