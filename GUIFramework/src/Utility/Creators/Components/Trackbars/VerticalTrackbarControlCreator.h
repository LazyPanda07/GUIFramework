#pragma once

#include "headers.h"
#include "Utility/Creators/BaseComponentCreator.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief Button creator
		class GUI_FRAMEWORK_API VerticalTrackbarControlCreator : public BaseComponentCreator
		{
		public:
			VerticalTrackbarControlCreator() = default;

			BaseComponent* create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComponent* parent) override;

			~VerticalTrackbarControlCreator() = default;
		};
	}
}
