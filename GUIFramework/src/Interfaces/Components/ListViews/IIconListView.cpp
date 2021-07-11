#include "pch.h"
#include "IIconListView.h"

using namespace std;

namespace gui_framework
{
	namespace interfaces
	{
		IIconListView::IIconListView(HWND handle, utility::IconsHolder& icons) :
			IBaseListViewOperations(handle),
			icons(icons)
		{

		}

		LRESULT IIconListView::addIconItem(const filesystem::path& pathToIcon)
		{
			LVITEMW item = {};

			if (!icons.contains(pathToIcon))
			{
				icons.addImage(pathToIcon);
			}

			item.mask = LVIF_IMAGE;
			item.iImage = icons[pathToIcon];

			return this->addItem(item);
		}

		filesystem::path IIconListView::getIconPath(size_t index) const
		{
			LVITEMW item = {};

			item.iItem = static_cast<int>(index);

			this->getItem(item);

			return icons[item.iImage];
		}

		size_t IIconListView::getIconIndex(size_t index) const
		{
			LVITEMW item = {};

			item.iItem = static_cast<int>(index);

			this->getItem(item);

			return item.iImage;
		}
	}
}
