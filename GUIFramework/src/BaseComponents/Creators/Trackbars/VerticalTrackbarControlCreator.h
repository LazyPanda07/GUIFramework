#pragma once

#include "BaseComponents/Creators/BaseComponentCreator.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief gui_framework::Button creator
		class GUI_FRAMEWORK_API VerticalTrackbarControlCreator : public BaseComponentCreator
		{
		public:
			VerticalTrackbarControlCreator() = default;

			BaseComponent* create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComponent* parent) override;

			~VerticalTrackbarControlCreator() = default;
		};
	}
}
