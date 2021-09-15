#pragma once

#include "headers.h"
#include "AdditionalCreationData.h"
#include "Components/TabControl.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief Specialization for TabControl
		template<>
		class GUI_FRAMEWORK_API AdditionalCreationData<TabControl>
		{
		protected:
			std::vector<TabControl::tabData> data;
			uint16_t imagesWidth;
			uint16_t imagesHeight;

		public:
			AdditionalCreationData() = default;

			AdditionalCreationData(const std::vector<TabControl::tabData>& data, uint16_t imagesWidth, uint16_t imagesHeight);

			virtual std::any getData() const;

			virtual ~AdditionalCreationData() = default;
		};
	}
}
