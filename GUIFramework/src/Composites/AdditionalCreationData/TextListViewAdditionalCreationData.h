#pragma once

#include "AdditionalCreationData.h"
#include "Components/ListView/TextListView.h"
#include "Components/ListView/ListTextListView.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief Specialization for gui_framework::TextListView
		template<>
		class GUI_FRAMEWORK_API AdditionalCreationData<TextListView>
		{
		protected:
			std::vector<std::wstring> items;

		public:
			AdditionalCreationData() = default;

			AdditionalCreationData(const std::vector<std::wstring>& items);

			virtual std::any getData() const;

			virtual ~AdditionalCreationData() = default;
		};

		/// @brief Specialization for gui_framework::ListTextListView
		template<>
		class GUI_FRAMEWORK_API AdditionalCreationData<ListTextListView>
		{
		protected:
			std::vector<std::wstring> items;

		public:
			AdditionalCreationData() = default;

			AdditionalCreationData(const std::vector<std::wstring>& items);

			virtual std::any getData() const;

			virtual ~AdditionalCreationData() = default;
		};
	}
}
