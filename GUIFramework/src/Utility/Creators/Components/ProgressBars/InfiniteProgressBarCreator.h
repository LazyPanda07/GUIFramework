#pragma once

#include "Utility/Creators/BaseComponentCreator.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief InfiniteProgressBar creator
		class GUI_FRAMEWORK_API InfiniteProgressBarCreator : public BaseComponentCreator
		{
		public:
			InfiniteProgressBarCreator() = default;

			BaseComponent* create(const std::wstring& windowName, const utility::ComponentSettings& settings, const std::any& additionalData, BaseComposite* parent) override;

			~InfiniteProgressBarCreator() = default;
		};
	}
}
