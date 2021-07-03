#pragma once

#include "IBaseListViewOperations.h"
#include "Utility/Holders/IconsHolder.h"

namespace gui_framework
{
	namespace interfaces
	{
		class GUI_FRAMEWORK_API IIconListView : public IBaseListViewOperations
		{
		private:
			utility::IconsHolder& icons;

		public:
			IIconListView(HWND handle, utility::IconsHolder& icons);

			virtual LRESULT addIconItem(const std::filesystem::path& pathToIcon);

			virtual ~IIconListView() = default;
		};
	}
}
