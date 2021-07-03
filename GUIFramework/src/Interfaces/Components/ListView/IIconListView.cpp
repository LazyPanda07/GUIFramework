#include "pch.h"
#include "IIconListView.h"

using namespace std;

namespace gui_framework
{
	namespace interfaces
	{
		IIconListView::IIconListView(HWND handle, utility::ImagesHolder& icons) :
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
	}
}
