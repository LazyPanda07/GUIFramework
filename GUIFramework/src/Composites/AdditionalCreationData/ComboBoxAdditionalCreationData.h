#pragma once

#include "AdditionalCreationData.h"
#include "Components/DropDownComboBox.h"
#include "Components/DropDownListComboBox.h"
#include "Components/SimpleComboBox.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief Specialization for gui_framework::DropDownComboBox
		template<>
		class GUI_FRAMEWORK_API AdditionalCreationData<DropDownComboBox>
		{
		protected:
			std::vector<std::wstring> values;

		public:
			AdditionalCreationData() = default;

			AdditionalCreationData(const std::vector<std::wstring>& values);

			virtual std::any getData() const;

			virtual ~AdditionalCreationData() = default;
		};

		/// @brief Specialization for gui_framework::DropDownListComboBox
		template<>
		class GUI_FRAMEWORK_API AdditionalCreationData<DropDownListComboBox>
		{
		protected:
			std::vector<std::wstring> values;

		public:
			AdditionalCreationData() = default;

			AdditionalCreationData(const std::vector<std::wstring>& values);

			virtual std::any getData() const;

			virtual ~AdditionalCreationData() = default;
		};

		/// @brief Specialization for gui_framework::SimpleComboBox
		template<>
		class GUI_FRAMEWORK_API AdditionalCreationData<SimpleComboBox>
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
