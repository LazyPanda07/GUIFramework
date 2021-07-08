#pragma once

#include "AdditionalCreationData.h"
#include "Components/ProgressBar.h"
#include "Components/InfiniteProgressBar.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief Specialization for gui_framework::ProgressBar
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

		/// @brief Specialization for gui_framework::InfiniteProgressBar
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
