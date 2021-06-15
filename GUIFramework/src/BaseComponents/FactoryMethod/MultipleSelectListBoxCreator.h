#pragma once

#include "BaseComponentCreator.h"

namespace gui_framework
{
	namespace utility
	{
		class MultipleSelectListBoxCreator : public BaseComponentCreator
		{
		public:
			MultipleSelectListBoxCreator() = default;

			BaseComponent* create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComponent* parent = nullptr) override;

			~MultipleSelectListBoxCreator() = default;
		};
	}
}
