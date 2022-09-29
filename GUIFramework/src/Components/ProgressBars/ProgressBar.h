#pragma once

#include "core.h"
#include "BaseComponents/StandardComponents/ProgressBars/BaseProgressBar.h"
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

		size_t getHash() const override;

		json::JSONBuilder getStructure() const override;

		~ProgressBar() = default;
	};
}
