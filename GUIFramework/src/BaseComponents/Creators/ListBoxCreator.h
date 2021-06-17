#pragma once

#include "BaseComponentCreator.h"

namespace gui_framework
{
	namespace utility
	{
		class ListBoxCreator : public BaseComponentCreator
		{
		public:
			ListBoxCreator() = default;

			BaseComponent* create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComponent* parent) override;

			~ListBoxCreator() = default;
		};
	}
}
