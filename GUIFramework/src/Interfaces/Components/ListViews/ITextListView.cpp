#include "ITextListView.h"

using namespace std;

namespace gui_framework
{
	namespace interfaces
	{
		void ITextListView::onRemove(size_t index)
		{
			textData.erase(index);
		}

		LVITEMW ITextListView::makeItem(const wstring& text, size_t index)
		{
			LVITEMW item = {};

			item.mask = LVIF_TEXT;
			item.pszText = const_cast<wchar_t*>(text.data());
			item.cchTextMax = static_cast<int>(text.size());
			item.iItem = static_cast<int>(index);

			return item;
		}

		ITextListView::ITextListView(HWND handle) :
			IBaseListViewOperations(handle)
		{

		}

		LRESULT ITextListView::addTextItem(const wstring& text)
		{
			return this->insertTextItem(text, this->size());
		}

		LRESULT ITextListView::addTextItem(const string& localizationKey)
		{
			return this->insertTextItem(localization::WTextLocalization::get()[localizationKey], this->size());
		}

		LRESULT ITextListView::insertTextItem(const wstring& text, size_t index)
		{	
			LRESULT result = this->addItem(this->makeItem(text, index));

			if (result != -1)
			{
				textData[static_cast<size_t>(result)] = text.size();
			}

			return result;
		}

		LRESULT ITextListView::insertTextItem(const string& localizationKey, size_t index)
		{
			return this->insertTextItem(localization::WTextLocalization::get()[localizationKey], this->size());
		}

		LRESULT ITextListView::changeTextItem(const wstring& text, size_t index)
		{
			return this->setItem(this->makeItem(text, index));
		}

		LRESULT ITextListView::changeTextItem(const string& localizationKey, size_t index)
		{
			return this->changeTextItem(localization::WTextLocalization::get()[localizationKey], index);
		}

		wstring ITextListView::getItemText(size_t index) const
		{
			LVITEMW item = {};
			wstring text;

			try
			{
				text.resize(textData.at(index) + 1);
			}
			catch (const out_of_range&)
			{
				return text;
			}

			item.iItem = static_cast<int>(index);
			item.mask = LVIF_TEXT;
			item.pszText = text.data();
			item.cchTextMax = static_cast<int>(text.size());

			this->getItem(item);

			text.pop_back();

			return text;
		}
	}
}
