#pragma once

#include "AdditionalCreationData.h"
#include "Components/ListViews/TextIconListView.h"
#include "Components/ListViews/ListTextIconListView.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief Specialization for gui_framework::TextIconListView
		template<>
		class GUI_FRAMEWORK_API AdditionalCreationData<TextIconListView>
		{
		protected:
			iconListViewType type;
			std::vector<std::pair<std::wstring, std::filesystem::path>> items;

		public:
			AdditionalCreationData() = default;

			AdditionalCreationData(iconListViewType type, const std::vector<std::pair<std::wstring, std::filesystem::path>>& items);

			virtual std::any getData() const;

			virtual ~AdditionalCreationData() = default;
		};

		/// @brief Specialization for gui_framework::ListTextIconListView
		template<>
		class GUI_FRAMEWORK_API AdditionalCreationData<ListTextIconListView>
		{
		protected:
			iconListViewType type;
			std::vector<std::pair<std::wstring, std::filesystem::path>> items;

		public:
			AdditionalCreationData() = default;

			AdditionalCreationData(iconListViewType type, const std::vector<std::pair<std::wstring, std::filesystem::path>>& items);

			virtual std::any getData() const;

			virtual ~AdditionalCreationData() = default;
		};
	}
}
