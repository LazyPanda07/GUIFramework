#pragma once

#include "headers.h"
#include "Utility/Creators/BaseComponentCreator.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief EditControl creator
		class GUI_FRAMEWORK_API EditControlCreator : public BaseComponentCreator
		{
		public:
			EditControlCreator() = default;

			BaseComponent* create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComponent* parent) override;

			~EditControlCreator() = default;
		};
	}
}
