#pragma once

#include "AdditionalCreationData.h"
#include "Components/ListView/IconListView.h"
#include "Components/ListView/ListIconListView.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief Specialization for gui_framework::IconListView
		template<>
		class GUI_FRAMEWORK_API AdditionalCreationData<IconListView>
		{
		protected:
			iconListViewType type;
			std::vector<std::filesystem::path> pathToIcons;

		public:
			AdditionalCreationData() = default;

			AdditionalCreationData(iconListViewType type, const std::vector<std::filesystem::path>& pathToIcons);

			virtual std::any getData() const;

			virtual ~AdditionalCreationData() = default;
		};

		/// @brief Specialization for gui_framework::ListIconListView
		template<>
		class GUI_FRAMEWORK_API AdditionalCreationData<ListIconListView>
		{
		protected:
			iconListViewType type;
			std::vector<std::filesystem::path> pathToIcons;

		public:
			AdditionalCreationData() = default;

			AdditionalCreationData(iconListViewType type, const std::vector<std::filesystem::path>& pathToIcons);

			virtual std::any getData() const;

			virtual ~AdditionalCreationData() = default;
		};
	}
}
