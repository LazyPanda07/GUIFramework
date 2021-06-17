#pragma once

#include "BaseComponentCreator.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief gui_framework::EditControl creator
		class GUI_FRAMEWORK_API EditControlCreator : public BaseComponentCreator
		{
		public:
			EditControlCreator() = default;

			BaseComponent* create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComponent* parent) override;

			~EditControlCreator() = default;
		};
	}
}
