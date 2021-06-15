#pragma once

#include "AdditionalCreationData.h"
#include "Components/Button.h"

namespace gui_framework
{
	namespace utility
	{
		template<>
		class AdditionalCreationData<Button>
		{
		protected:
			std::wstring text;
			std::function<LRESULT(WPARAM, LPARAM)> onClick;

		public:
			AdditionalCreationData() = default;

			AdditionalCreationData(const std::wstring text, const std::function<LRESULT(WPARAM, LPARAM)>& onClick);

			virtual std::any getData() const final;

			virtual ~AdditionalCreationData() = default;
		};
	}
}
