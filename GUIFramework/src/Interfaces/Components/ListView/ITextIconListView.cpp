#include "pch.h"
#include "ITextIconListView.h"

using namespace std;

namespace gui_framework
{
	namespace interfaces
	{
		ITextIconListView::ITextIconListView(HWND handle, utility::ImagesHolder& images) :
			IBaseListViewOperations(handle),
			images(images)
		{

		}

		LRESULT ITextIconListView::addTextIconItem(const wstring& text, const filesystem::path& pathToIcon)
		{
			LVITEMW item = {};

			if (!images.contains(pathToIcon))
			{
				images.addImage(pathToIcon, utility::ImagesHolder::imageType::icon);
			}

			item.mask = LVIF_TEXT | LVIF_IMAGE;
			item.pszText = const_cast<wchar_t*>(text.data());
			item.cchTextMax = static_cast<int>(text.size());
			item.iImage = images[pathToIcon];

			return this->addItem(item);
		}
	}
}
