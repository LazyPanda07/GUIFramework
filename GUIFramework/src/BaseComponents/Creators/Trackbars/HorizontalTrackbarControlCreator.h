#pragma once

#include "BaseComponents/Creators/BaseComponentCreator.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief Button creator
		class GUI_FRAMEWORK_API HorizontalTrackbarControlCreator : public BaseComponentCreator
		{
		public:
			HorizontalTrackbarControlCreator() = default;

			BaseComponent* create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComponent* parent) override;

			~HorizontalTrackbarControlCreator() = default;
		};
	}
}
