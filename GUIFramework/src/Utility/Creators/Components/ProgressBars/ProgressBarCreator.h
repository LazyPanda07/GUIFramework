#pragma once

#include "Utility/Creators/BaseComponentCreator.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief ProgressBar creator
		class GUI_FRAMEWORK_API ProgressBarCreator : public BaseComponentCreator
		{
		public:
			ProgressBarCreator() = default;

			BaseComponent* create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComposite* parent) override;

			~ProgressBarCreator() = default;
		};
	}
}
