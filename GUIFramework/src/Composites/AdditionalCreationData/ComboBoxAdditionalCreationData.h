#pragma once

#include "headers.h"
#include "AdditionalCreationData.h"
#include "Components/ComboBoxes/DropDownComboBox.h"
#include "Components/ComboBoxes/DropDownListComboBox.h"
#include "Components/ComboBoxes/SimpleComboBox.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief Specialization for DropDownComboBox
		template<>
		class GUI_FRAMEWORK_API AdditionalCreationData<DropDownComboBox>
		{
		protected:
			std::vector<std::wstring> values;
			std::function<void(BaseComboBox&)> onSelectionChange;
			std::string functionName;
			std::string moduleName;

		public:
			AdditionalCreationData() = default;

			AdditionalCreationData(const std::vector<std::wstring>& values, const std::function<void(BaseComboBox&)>& onSelectionChange = nullptr);

			AdditionalCreationData(const std::vector<std::wstring>& values, const std::string& functionName, const std::string& moduleName);

			virtual std::any getData() const;

			virtual ~AdditionalCreationData() = default;
		};

		/// @brief Specialization for DropDownListComboBox
		template<>
		class GUI_FRAMEWORK_API AdditionalCreationData<DropDownListComboBox>
		{
		protected:
			std::vector<std::wstring> values;
			std::function<void(BaseComboBox&)> onSelectionChange;
			std::string functionName;
			std::string moduleName;

		public:
			AdditionalCreationData() = default;

			AdditionalCreationData(const std::vector<std::wstring>& values, const std::function<void(BaseComboBox&)>& onSelectionChange = nullptr);

			AdditionalCreationData(const std::vector<std::wstring>& values, const std::string& functionName, const std::string& moduleName);

			virtual std::any getData() const;

			virtual ~AdditionalCreationData() = default;
		};

		/// @brief Specialization for SimpleComboBox
		template<>
		class GUI_FRAMEWORK_API AdditionalCreationData<SimpleComboBox>
		{
		protected:
			std::vector<std::wstring> values;
			std::function<void(BaseComboBox&)> onSelectionChange;
			std::string functionName;
			std::string moduleName;

		public:
			AdditionalCreationData() = default;

			AdditionalCreationData(const std::vector<std::wstring>& values, const std::function<void(BaseComboBox&)>& onSelectionChange = nullptr);

			AdditionalCreationData(const std::vector<std::wstring>& values, const std::string& functionName, const std::string& moduleName);

			virtual std::any getData() const;

			virtual ~AdditionalCreationData() = default;
		};
	}
}
