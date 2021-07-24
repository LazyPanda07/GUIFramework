#pragma once

#include "pch.h"
#include "IBaseListViewOperations.h"
#include "Utility/Holders/LoadableHolders/IconsHolder.h"

namespace gui_framework
{
	namespace interfaces
	{
		/// @brief Provides adding icon items for list views
		class GUI_FRAMEWORK_API IIconListView : public IBaseListViewOperations
		{
		private:
			utility::IconsHolder& icons;

		public:
			IIconListView(HWND handle, utility::IconsHolder& icons);

			virtual LRESULT addIconItem(const std::filesystem::path& pathToIcon);

			virtual std::filesystem::path getIconPath(size_t index) const;

			virtual size_t getIconIndex(size_t index) const;

			virtual ~IIconListView() = default;
		};
	}
}
