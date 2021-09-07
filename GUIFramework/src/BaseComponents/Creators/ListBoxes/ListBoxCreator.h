#pragma once

#include "headers.h"
#include "BaseComponents/Creators/BaseComponentCreator.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief ListBox creator
		class GUI_FRAMEWORK_API ListBoxCreator : public BaseComponentCreator
		{
		public:
			ListBoxCreator() = default;

			BaseComponent* create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComponent* parent) override;

			~ListBoxCreator() = default;
		};
	}
}
