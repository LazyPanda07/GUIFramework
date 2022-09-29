#pragma once

#include "core.h"
#include "AdditionalCreationData.h"
#include "Components/ProgressBars/ProgressBar.h"
#include "Components/ProgressBars/InfiniteProgressBar.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief Specialization for ProgressBar
		template<>
		class GUI_FRAMEWORK_API AdditionalCreationData<ProgressBar>
		{
		protected:
			int minRange;
			int maxRange;
			int updateStep;

		public:
			AdditionalCreationData(int minRange = ProgressBar::defaultMinRange, int maxRange = ProgressBar::defaultMaxRange, int updateStep = ProgressBar::defaultUpdateStep);

			virtual std::any getData() const;

			virtual ~AdditionalCreationData() = default;
		};

		/// @brief Specialization for InfiniteProgressBar
		template<>
		class GUI_FRAMEWORK_API AdditionalCreationData<InfiniteProgressBar>
		{
		protected:
			int animationPeriod;

		public:
			AdditionalCreationData(int animationPeriod = NULL);

			virtual std::any getData() const;

			virtual ~AdditionalCreationData() = default;
		};
	}
}
