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
			return this->insertTextIconItem(text, pathToIcon, this->size());
		}

		LRESULT ITextIconListView::insertTextIconItem(const wstring& text, const filesystem::path& pathToIcon, size_t index)
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
			item.iItem = static_cast<int>(index);

			return this->addItem(item);
		}

		tuple<wstring, uint16_t, filesystem::path> ITextIconListView::getTextIconItem(size_t index) const
		{
			LVITEMW item = {};
			wstring text;

			item.iItem = static_cast<int>(index);

			this->getItem(item);

			if (item.pszText)
			{
				text = item.pszText;
			}

			return make_tuple(text, static_cast<uint16_t>(item.iImage), icons[item.iImage]);
		}
	}
}
