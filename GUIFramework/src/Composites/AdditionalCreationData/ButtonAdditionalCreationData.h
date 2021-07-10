#pragma once

#include "AdditionalCreationData.h"
#include "Components/Button.h"
#include "Components/CheckBox.h"

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
			std::function<void()> onClick;

		public:
			AdditionalCreationData() = default;

			AdditionalCreationData(const std::wstring text, const std::function<void()>& onClick);

			virtual std::any getData() const;

			virtual ~AdditionalCreationData() = default;
		};

		/// @brief Specialization for gui_framework::CheckBox
		template<>
		class GUI_FRAMEWORK_API AdditionalCreationData<CheckBox>
		{
		protected:
			std::wstring text;
			std::function<void()> onCheck;
			std::function<void()> onClear;
			std::function<void()> onClick;

		public:
			AdditionalCreationData() = default;

			AdditionalCreationData(const std::wstring text, const std::function<void()>& onCheck, const std::function<void()>& onClear, const std::function<void()>& onClick = nullptr);

			virtual std::any getData() const;

			virtual ~AdditionalCreationData() = default;
		};
	}
}
