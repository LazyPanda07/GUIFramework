#pragma once

#include "AdditionalCreationData.h"
#include "Components/DropDownComboBox.h"
#include "Components/DropDownListComboBox.h"
#include "Components/SimpleComboBox.h"

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

		template<>
		class AdditionalCreationData<DropDownListComboBox>
		{
		protected:
			std::vector<std::wstring> values;

		public:
			AdditionalCreationData() = default;

			AdditionalCreationData(const std::vector<std::wstring>& values);

			virtual std::any getData() const;

			virtual ~AdditionalCreationData() = default;
		};

		template<>
		class AdditionalCreationData<SimpleComboBox>
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
