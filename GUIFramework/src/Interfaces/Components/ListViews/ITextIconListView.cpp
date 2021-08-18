#include "pch.h"
#include "ITextIconListView.h"

using namespace std;

namespace gui_framework
{
	namespace interfaces
	{
		void ITextIconListView::onRemove(size_t index)
		{
			textData.erase(index);
		}

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
			LRESULT result;

			if (!icons.contains(pathToIcon))
			{
				icons.addImage(pathToIcon);
			}

			item.mask = LVIF_TEXT | LVIF_IMAGE;
			item.pszText = const_cast<wchar_t*>(text.data());
			item.cchTextMax = static_cast<int>(text.size());
			item.iImage = icons[pathToIcon];
			item.iItem = static_cast<int>(index);

			result = this->addItem(item);

			if (result != -1)
			{
				textData[index] = text.size();
			}

			return result;
		}

		tuple<wstring, uint16_t, filesystem::path> ITextIconListView::getTextIconItem(size_t index) const
		{
			LVITEMW item = {};
			wstring text;

			try
			{
				text.resize(textData.at(index) + 1);
			}
			catch (const out_of_range&)
			{
				return {};
			}

			item.iItem = static_cast<int>(index);
			item.mask = LVIF_TEXT | LVIF_IMAGE;
			item.pszText = text.data();
			item.cchTextMax = static_cast<int>(text.size());

			this->getItem(item);

			text.pop_back();

			return { text, static_cast<uint16_t>(item.iImage), icons[item.iImage] };
		}
	}
}
