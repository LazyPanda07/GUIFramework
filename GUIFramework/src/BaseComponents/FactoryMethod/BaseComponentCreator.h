#pragma once

#include "BaseComponents/BaseComponent.h"

namespace gui_framework
{
	namespace utility
	{
		class BaseComponentCreator
		{
		public:
			BaseComponentCreator() = default;

			virtual BaseComponent* create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComponent* parent = nullptr) = 0;

			virtual ~BaseComponentCreator() = default;
		};
	}
}
