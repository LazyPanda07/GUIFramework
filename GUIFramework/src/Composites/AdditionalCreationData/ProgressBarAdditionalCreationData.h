#pragma once

#include "AdditionalCreationData.h"
#include "Components/ProgressBar.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief Specialization for gui_framework::ProgressBar
		template<>
		class GUI_FRAMEWORK_API AdditionalCreationData<ProgressBar>
		{
		protected:
			int updateStep;

		public:
			AdditionalCreationData(int updateStep = 0);

			virtual std::any getData() const;

			virtual ~AdditionalCreationData() = default;
		};
	}
}
