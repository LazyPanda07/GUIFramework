#pragma once

#include "BaseComponentCreator.h"

namespace gui_framework
{
	namespace utility
	{
		class ChildWindowCreator : public BaseComponentCreator
		{
		public:
			ChildWindowCreator() = default;

			BaseComponent* create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComponent* parent) override;

			~ChildWindowCreator() = default;
		};
	}
}
