#pragma once

#include "BaseComponentCreator.h"

namespace gui_framework
{
	namespace utility
	{
		class EditControlCreator : public BaseComponentCreator
		{
		public:
			EditControlCreator() = default;

			BaseComponent* create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComponent* parent) override;

			~EditControlCreator() = default;
		};
	}
}