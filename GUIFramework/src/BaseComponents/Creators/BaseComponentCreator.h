#pragma once

#include "pch.h"
#include "BaseComponents/BaseComponent.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief Interface for components creation(factory method pattern)
		class GUI_FRAMEWORK_API BaseComponentCreator
		{
		public:
			BaseComponentCreator() = default;

			virtual BaseComponent* create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComponent* parent) = 0;

			virtual ~BaseComponentCreator() = default;
		};
	}
}
