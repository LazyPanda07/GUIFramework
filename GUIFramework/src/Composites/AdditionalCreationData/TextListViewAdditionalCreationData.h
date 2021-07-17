#pragma once

#include "pch.h"
#include "AdditionalCreationData.h"
#include "Components/ListViews/TextListView.h"
#include "Components/ListViews/ListTextListView.h"

namespace gui_framework
{
	namespace utility
	{
		/// @brief Specialization for TextListView
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

		/// @brief Specialization for ListTextListView
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
