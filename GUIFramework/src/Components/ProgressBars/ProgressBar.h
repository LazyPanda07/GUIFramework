#pragma once

#include "pch.h"
#include "BaseComponents/StandardComponents/BaseProgressBar.h"
#include "Interfaces/Components/IResizableComponent.h"

namespace gui_framework
{
	/// @brief Standard updatable progress bar
	class GUI_FRAMEWORK_API ProgressBar :
		public BaseProgressBar,
		public interfaces::IResizableComponent
	{
	public:
		ProgressBar(const std::wstring& progressBarName, const utility::ComponentSettings& settings, BaseComponent* parent, int minRange = defaultMinRange, int maxRange = defaultMaxRange, int updateStep = defaultUpdateStep);

		~ProgressBar() = default;
	};
}
