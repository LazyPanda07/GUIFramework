#pragma once

#include "AdditionalCreationData.h"
#include "Components/ListBox.h"
#include "Components/MultipleSelectListBox.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief Specialization for gui_framework::ListBox
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

		/// @brief Specialization for gui_framework::MultipleSelectListBox
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
