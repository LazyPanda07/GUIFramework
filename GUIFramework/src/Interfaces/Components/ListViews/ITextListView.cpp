#include "pch.h"
#include "ITextListView.h"

using namespace std;

namespace gui_framework
{
	namespace interfaces
	{
		ITextListView::ITextListView(HWND handle) :
			IBaseListViewOperations(handle)
		{

		}

		LRESULT ITextListView::addTextItem(const wstring& text)
		{
			return this->insertTextItem(text, this->size());
		}

		LRESULT ITextListView::insertTextItem(const wstring& text, size_t index)
		{
			LVITEMW item = {};

			item.mask = LVIF_TEXT;
			item.pszText = const_cast<wchar_t*>(text.data());
			item.cchTextMax = static_cast<int>(text.size());
			item.iItem = static_cast<int>(index);

			return this->addItem(item);
		}

		wstring ITextListView::getItemText(size_t index) const
		{
			LVITEMW item = {};

			item.iItem = static_cast<int>(index);

			this->getItem(item);

			if (item.pszText)
			{
				return wstring(item.pszText);
			}

			return wstring();
		}
	}
}
