#pragma once

#include "pch.h"
#include "AdditionalCreationData.h"
#include "Components/ListViews/IconListView.h"
#include "Components/ListViews/ListIconListView.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief Specialization for IconListView
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

		/// @brief Specialization for ListIconListView
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
