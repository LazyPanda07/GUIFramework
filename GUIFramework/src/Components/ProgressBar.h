#pragma once

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
		ProgressBar(const std::wstring& progressBarName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent, int minRange = defaultMinRange, int maxRange = defaultMaxRange, int updateStep = defaultUpdateStep);

		~ProgressBar() = default;
	};
}
