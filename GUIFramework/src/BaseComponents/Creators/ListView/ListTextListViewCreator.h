#pragma once

#include "BaseComponents/Creators/BaseComponentCreator.h"

namespace gui_framework
{
	namespace utility
	{
		class GUI_FRAMEWORK_API ListTextListViewCreator : public BaseComponentCreator
		{
		public:
			ListTextListViewCreator() = default;

			BaseComponent* create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComponent* parent) override;

			~ListTextListViewCreator() = default;
		};
	}
}
