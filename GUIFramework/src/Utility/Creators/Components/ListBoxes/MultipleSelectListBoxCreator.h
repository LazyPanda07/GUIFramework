#pragma once

#include "Utility/Creators/BaseComponentCreator.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief MultipleSelectListBox creator
		class GUI_FRAMEWORK_API MultipleSelectListBoxCreator : public BaseComponentCreator
		{
		public:
			MultipleSelectListBoxCreator() = default;

			BaseComponent* create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComposite* parent) override;

			~MultipleSelectListBoxCreator() = default;
		};
	}
}
