#pragma once

#include "BaseComponentCreator.h"

namespace gui_framework
{
	namespace utility
	{
		class StaticControlCreator : public BaseComponentCreator
		{
		public:
			StaticControlCreator() = default;

			BaseComponent* create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComponent* parent) override;

			~StaticControlCreator() = default;
		};
	}
}
