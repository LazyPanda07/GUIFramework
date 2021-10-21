#include "headers.h"
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
			return this->insertIconItem(pathToIcon, this->size());
		}

		LRESULT IIconListView::insertIconItem(const filesystem::path& pathToIcon, size_t index)
		{
			LVITEMW item = {};

			if (!icons.contains(pathToIcon))
			{
				icons.addImage(pathToIcon);
			}

			item.mask = LVIF_IMAGE;
			item.iImage = icons[pathToIcon];
			item.iItem = static_cast<int>(index);

			return this->addItem(item);
		}

		filesystem::path IIconListView::getIconPath(size_t index) const
		{
			LVITEMW item = {};

			item.iItem = static_cast<int>(index);
			item.mask = LVIF_IMAGE;

			this->getItem(item);

			return icons[item.iImage];
		}

		size_t IIconListView::getIconIndex(size_t index) const
		{
			LVITEMW item = {};

			item.iItem = static_cast<int>(index);
			item.mask = LVIF_IMAGE;

			this->getItem(item);

			return item.iImage;
		}
	}
}
