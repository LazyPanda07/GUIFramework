#pragma once

#include "BaseComponentCreator.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief gui_framework::MultipleSelectListBox creator
		class GUI_FRAMEWORK_API MultipleSelectListBoxCreator : public BaseComponentCreator
		{
		public:
			MultipleSelectListBoxCreator() = default;

			BaseComponent* create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComponent* parent) override;

			~MultipleSelectListBoxCreator() = default;
		};
	}
}
