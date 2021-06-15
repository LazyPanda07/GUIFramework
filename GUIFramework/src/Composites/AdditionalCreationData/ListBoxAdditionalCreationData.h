#pragma once

#include "AdditionalCreationData.h"
#include "Components/ListBox.h"
#include "Components/MultipleSelectListBox.h"

namespace gui_framework
{
	namespace utility
	{
		template<>
		class AdditionalCreationData<ListBox>
		{
		protected:
			std::vector<std::wstring> values;
			bool isSorting;

		public:
			AdditionalCreationData() = default;

			AdditionalCreationData(const std::vector<std::wstring>& values, bool isSorting = false);

			virtual std::any getData() const;

			virtual ~AdditionalCreationData() = default;
		};

		template<>
		class AdditionalCreationData<MultipleSelectListBox>
		{
		protected:
			std::vector<std::wstring> values;
			bool isSorting;

		public:
			AdditionalCreationData() = default;

			AdditionalCreationData(const std::vector<std::wstring>& values, bool isSorting = false);

			virtual std::any getData() const;

			virtual ~AdditionalCreationData() = default;
		};
	}
}
