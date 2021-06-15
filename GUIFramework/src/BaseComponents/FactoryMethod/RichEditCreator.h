#pragma once

#include "BaseComponentCreator.h"

namespace gui_framework
{
	namespace utility
	{
		class RichEditCreator : public BaseComponentCreator
		{
		public:
			RichEditCreator() = default;

			BaseComponent* create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComponent* parent = nullptr) override;

			~RichEditCreator() = default;
		};
	}
}
