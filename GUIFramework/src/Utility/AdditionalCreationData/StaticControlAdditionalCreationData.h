#pragma once

#include "AdditionalCreationData.h"
#include "Components/StaticControl.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief Specialization for StaticControl
		template<>
		class GUI_FRAMEWORK_API AdditionalCreationData<StaticControl>
		{
		protected:
			std::wstring text;

		public:
			AdditionalCreationData(const std::wstring& text = L"");

			virtual std::any getData() const;

			virtual ~AdditionalCreationData() = default;
		};
	}
}
