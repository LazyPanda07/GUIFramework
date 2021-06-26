#include "pch.h"
#include "IIconListView.h"

using namespace std;

namespace gui_framework
{
	namespace interfaces
	{
		IIconListView::IIconListView(HWND handle, utility::ImagesHolder& images) :
			IBaseListViewOperations(handle),
			images(images)
		{

		}

		LRESULT IIconListView::addIconItem(const filesystem::path& pathToIcon)
		{
			LVITEMW item = {};

			if (!images.contains(pathToIcon))
			{
				images.addImage(pathToIcon, utility::ImagesHolder::imageType::icon);
			}

			item.mask = LVIF_IMAGE;
			item.iImage = images[pathToIcon];

			return this->addItem(item);
		}
	}
}
