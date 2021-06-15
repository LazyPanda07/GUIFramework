#pragma once

#include "AdditionalCreationData.h"
#include "Components/DropDownComboBox.h"

namespace gui_framework
{
	namespace utility
	{
		template<>
		class AdditionalCreationData<DropDownComboBox>
		{
		protected:
			std::vector<std::wstring> values;

		public:
			AdditionalCreationData() = default;

			AdditionalCreationData(const std::vector<std::wstring>& values);

			virtual std::any getData() const;

			virtual ~AdditionalCreationData() = default;
		};
	}
}
