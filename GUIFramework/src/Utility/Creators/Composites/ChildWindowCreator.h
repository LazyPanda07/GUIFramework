#pragma once

#include "Utility/Creators/BaseComponentCreator.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief ChildWindow creator
		class GUI_FRAMEWORK_API ChildWindowCreator : public BaseComponentCreator
		{
		public:
			ChildWindowCreator() = default;

			BaseComponent* create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComposite* parent) override;

			~ChildWindowCreator() = default;
		};
	}
}
