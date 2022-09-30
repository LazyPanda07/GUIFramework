#pragma once

#include "AdditionalCreationData.h"
#include "Components/ListBoxes/ListBox.h"
#include "Components/ListBoxes/MultipleSelectListBox.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief Specialization for ListBox
		template<>
		class GUI_FRAMEWORK_API AdditionalCreationData<ListBox>
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

		/// @brief Specialization for MultipleSelectListBox
		template<>
		class GUI_FRAMEWORK_API AdditionalCreationData<MultipleSelectListBox>
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
