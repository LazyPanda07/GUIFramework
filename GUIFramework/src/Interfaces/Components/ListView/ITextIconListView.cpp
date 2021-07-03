#include "pch.h"
#include "ITextIconListView.h"

using namespace std;

namespace gui_framework
{
	namespace interfaces
	{
		ITextIconListView::ITextIconListView(HWND handle, utility::IconsHolder& icons) :
			IBaseListViewOperations(handle),
			icons(icons)
		{

		}

		LRESULT ITextIconListView::addTextIconItem(const wstring& text, const filesystem::path& pathToIcon)
		{
			LVITEMW item = {};

			if (!icons.contains(pathToIcon))
			{
				icons.addImage(pathToIcon);
			}

			item.mask = LVIF_TEXT | LVIF_IMAGE;
			item.pszText = const_cast<wchar_t*>(text.data());
			item.cchTextMax = static_cast<int>(text.size());
			item.iImage = icons[pathToIcon];

			return this->addItem(item);
		}
	}
}
