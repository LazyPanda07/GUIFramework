#pragma once

#include "IBaseListViewOperations.h"
#include "Utility/ImagesHolder.h"

namespace gui_framework
{
	namespace interfaces
	{
		class GUI_FRAMEWORK_API IIconListView : public IBaseListViewOperations
		{
		private:
			utility::ImagesHolder& images;

		public:
			IIconListView(HWND handle, utility::ImagesHolder& images);

			virtual LRESULT addIconItem(const std::filesystem::path& pathToIcon);

			virtual ~IIconListView() = default;
		};
	}
}
