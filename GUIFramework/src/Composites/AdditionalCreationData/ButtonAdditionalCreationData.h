#pragma once

#include "AdditionalCreationData.h"
#include "Components/Button.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief Specialization for gui_framework::Button
		template<>
		class GUI_FRAMEWORK_API AdditionalCreationData<Button>
		{
		protected:
			std::wstring text;
			std::function<LRESULT(WPARAM, LPARAM)> onClick;

		public:
			AdditionalCreationData() = default;

			AdditionalCreationData(const std::wstring text, const std::function<LRESULT(WPARAM, LPARAM)>& onClick);

			virtual std::any getData() const;

			virtual ~AdditionalCreationData() = default;
		};
	}
}
