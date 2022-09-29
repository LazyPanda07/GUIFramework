#include "core.h"
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

		LVITEMW ITextIconListView::makeItem(const std::wstring& text, const std::filesystem::path& pathToIcon, size_t index)
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

			return item;
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

		LRESULT ITextIconListView::addTextIconItem(const string& localizationKey, const filesystem::path& pathToIcon)
		{
			return this->addTextIconItem(localization::WTextLocalization::get()[localizationKey], pathToIcon);
		}

		LRESULT ITextIconListView::insertTextIconItem(const wstring& text, const filesystem::path& pathToIcon, size_t index)
		{
			LRESULT result = this->addItem(this->makeItem(text, pathToIcon, index));

			if (result != -1)
			{
				textData[index] = text.size();
			}

			return result;
		}

		LRESULT ITextIconListView::insertTextIconItem(const string& localizationKey, const filesystem::path& pathToIcon, size_t index)
		{
			return this->insertTextIconItem(localization::WTextLocalization::get()[localizationKey], pathToIcon, index);
		}

		LRESULT ITextIconListView::changeTextIconItem(const wstring& text, const filesystem::path& pathToIcon, size_t index)
		{
			LRESULT result = this->setItem(this->makeItem(text, pathToIcon, index));

			if (result != -1)
			{
				textData[index] = text.size();
			}

			return result;
		}

		LRESULT ITextIconListView::changeTextIconItem(const string& localizationKey, const filesystem::path& pathToIcon, size_t index)
		{
			return this->changeTextIconItem(localization::WTextLocalization::get()[localizationKey], pathToIcon, index);
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
