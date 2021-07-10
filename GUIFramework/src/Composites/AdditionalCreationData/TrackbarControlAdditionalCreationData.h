#pragma once

#include "AdditionalCreationData.h"
#include "Components/Trackbars/HorizontalTrackbarControl.h"
#include "Components/Trackbars/VerticalTrackbarControl.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief Specialization for gui_framework::HorizontalTrackbarControl
		template<>
		class GUI_FRAMEWORK_API AdditionalCreationData<HorizontalTrackbarControl>
		{
		protected:
			bool autoTicks;
			HorizontalTrackbarControl::horizontalTickPosition position;
			bool selectionRange;
			bool noTicks;

		public:
			AdditionalCreationData(bool autoTicks = true, HorizontalTrackbarControl::horizontalTickPosition position = HorizontalTrackbarControl::horizontalTickPosition::bottom, bool selectionRange = false, bool noTicks = false);

			virtual std::any getData() const;

			virtual ~AdditionalCreationData() = default;
		};

		/// @brief Specialization for gui_framework::VerticalTrackbarControl
		template<>
		class GUI_FRAMEWORK_API AdditionalCreationData<VerticalTrackbarControl>
		{
		protected:
			bool autoTicks;
			VerticalTrackbarControl::verticalTickPosition position;
			bool selectionRange;
			bool noTicks;

		public:
			AdditionalCreationData(bool autoTicks = true, VerticalTrackbarControl::verticalTickPosition position = VerticalTrackbarControl::verticalTickPosition::left, bool selectionRange = false, bool noTicks = false);

			virtual std::any getData() const;

			virtual ~AdditionalCreationData() = default;
		};
	}
}
