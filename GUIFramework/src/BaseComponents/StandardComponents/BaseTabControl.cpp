#include "pch.h"
#include "BaseTabControl.h"

#include "Styles/DefaultStyles.h"
#include "Exceptions/FileDoesNotExist.h"
#include "Exceptions/NotImplemented.h"

#pragma warning(disable: 26454)

using namespace std;

namespace gui_framework
{
	using tabData = BaseTabControl::tabData;

	tabData::tabData(const wstring& text, const filesystem::path& pathToImage, const function<void()>& callback) :
		text(text),
		pathToImage(pathToImage),
		callback(callback)
	{

	}

	LRESULT BaseTabControl::windowMessagesHandle(HWND handle, UINT message, WPARAM wparam, LPARAM lparam, bool& isUsed)
	{
		if (message == WM_NOTIFY)
		{
			NMHDR* notification = reinterpret_cast<NMHDR*>(lparam);

			if (notification->code == TCN_SELCHANGE)
			{
				isUsed = true;

				LRESULT currentTab = this->getSelectedTab();

				if (currentTab != -1)
				{
					callbacks[currentTab]();
				}

				return 0;
			}
		}

		isUsed = false;

		return -1;
	}

	BaseTabControl::BaseTabControl(const wstring& tabControlName, const utility::ComponentSettings& settings, uint16_t imagesWidth, uint16_t imagesHeight, BaseComponent* parent) :
		BaseComponent
		(
			wstring(standard_classes::tabControl),
			tabControlName,
			settings,
			styles::DefaultStyles(),
			parent
		),
		images(imagesWidth, imagesHeight)
	{
		SendMessageW(handle, TCM_SETIMAGELIST, NULL, reinterpret_cast<LPARAM>(images.getImageList()));
	}

	LRESULT BaseTabControl::appendText(const wstring& text, const function<void()>& onClick)
	{
		return this->insertText(this->size(), text, onClick);
	}

	LRESULT BaseTabControl::insertText(size_t index, const wstring& text, const function<void()>& onClick)
	{
		TCITEMW item = {};

		item.mask = TCIF_TEXT;
		item.pszText = const_cast<wchar_t*>(text.data());
		item.cchTextMax = static_cast<int>(text.size());

		LRESULT result = SendMessageW(handle, TCM_INSERTITEM, index, reinterpret_cast<LPARAM>(&item));

		if (result != -1)
		{
			auto it = callbacks.insert(callbacks.begin() + index, onClick);

			tabs.emplace(tabs.begin() + index, text, filesystem::path(), *it);
		}

		return result;
	}

	LRESULT BaseTabControl::appendImage(const filesystem::path& pathToImage, const function<void()>& onClick)
	{
		return this->insertImage(this->size(), pathToImage, onClick);
	}

	LRESULT BaseTabControl::insertImage(size_t index, const filesystem::path& pathToImage, const function<void()>& onClick)
	{
		if (!filesystem::exists(pathToImage))
		{
			throw exceptions::FileDoesNotExist(pathToImage);
		}

		TCITEMW item = {};

		if (!images.contains(pathToImage))
		{
			images.addImage(pathToImage);
		}

		item.mask = TCIF_IMAGE;
		item.iImage = images[pathToImage];

		LRESULT result = SendMessageW(handle, TCM_INSERTITEM, index, reinterpret_cast<LPARAM>(&item));

		if (result != -1)
		{
			auto it = callbacks.insert(callbacks.begin() + index, onClick);

			tabs.emplace(tabs.begin() + index, wstring(), pathToImage, *it);
		}

		return result;
	}

	LRESULT BaseTabControl::appendTextAndImage(const wstring& text, const filesystem::path& pathToImage, const function<void()>& onClick)
	{
		return this->insertTextAndImage(this->size(), text, pathToImage, onClick);
	}

	LRESULT BaseTabControl::insertTextAndImage(size_t index, const wstring& text, const filesystem::path& pathToImage, const function<void()>& onClick)
	{
		if (!filesystem::exists(pathToImage))
		{
			throw exceptions::FileDoesNotExist(pathToImage);
		}

		TCITEMW item = {};

		if (!images.contains(pathToImage))
		{
			images.addImage(pathToImage);
		}

		item.mask = TCIF_TEXT | TCIF_IMAGE;
		item.pszText = const_cast<wchar_t*>(text.data());
		item.cchTextMax = static_cast<int>(text.size());
		item.iImage = images[pathToImage];

		LRESULT result = SendMessageW(handle, TCM_INSERTITEM, index, reinterpret_cast<LPARAM>(&item));

		if (result != -1)
		{
			auto it = callbacks.insert(callbacks.begin() + index, onClick);

			tabs.emplace(tabs.begin() + index, text, pathToImage, *it);
		}

		return result;
	}

	bool BaseTabControl::removeTab(size_t index)
	{
		bool result = SendMessageW(handle, TCM_DELETEITEM, static_cast<WPARAM>(index), NULL);

		if (result)
		{
			callbacks.erase(callbacks.begin() + index);

			tabs.erase(tabs.begin() + index);
		}

		return result;
	}

	bool BaseTabControl::clear()
	{
		bool result = SendMessageW(handle, TCM_DELETEALLITEMS, NULL, NULL);

		if (result)
		{
			callbacks.clear();

			tabs.clear();
		}

		return result;
	}

	size_t BaseTabControl::size() const
	{
		return SendMessageW(handle, TCM_GETITEMCOUNT, NULL, NULL);
	}

	bool BaseTabControl::setItem(size_t index, const function<void()>& callback, const wstring& text, const filesystem::path& pathToImage)
	{
		if (!pathToImage.empty() && !filesystem::exists(pathToImage))
		{
			throw exceptions::FileDoesNotExist(pathToImage);
		}

		TCITEMW item = {};

		if (text.size())
		{
			item.mask |= TCIF_TEXT;

			item.pszText = const_cast<wchar_t*>(text.data());
			item.cchTextMax = static_cast<int>(text.size());
		}

		if (!pathToImage.empty())
		{
			if (!images.contains(pathToImage))
			{
				images.addImage(pathToImage);
			}

			item.mask |= TCIF_IMAGE;

			item.iImage = images[pathToImage];
		}

		bool result = SendMessageW(handle, TCM_SETITEM, index, reinterpret_cast<LPARAM>(&item));

		if (result)
		{
			callbacks[index] = callback;

			tabs[index] = tabData(text, pathToImage, callback);
		}

		return result;
	}

	LRESULT BaseTabControl::setSelection(size_t index)
	{
		return SendMessageW(handle, TCM_SETCURSEL, static_cast<WPARAM>(index), NULL);
	}

	const BaseTabControl::tabData& BaseTabControl::getItem(size_t index) const
	{
		return tabs.at(index);
	}

	LRESULT BaseTabControl::getSelectedTab() const
	{
		return SendMessageW(handle, TCM_GETCURSEL, NULL, NULL);
	}

	uint16_t BaseTabControl::getImagesWidth() const
	{
		return images.getImagesWidth();
	}

	uint16_t BaseTabControl::getImagesHeight() const
	{
		return images.getImagesHeight();
	}

	void BaseTabControl::setBackgroundColor(uint8_t red, uint8_t green, uint8_t blue)
	{
		throw exceptions::NotImplemented(__FUNCTION__, "BaseComboBox");
	}

	void BaseTabControl::setTextColor(uint8_t red, uint8_t green, uint8_t blue)
	{
		throw exceptions::NotImplemented(__FUNCTION__, "BaseComboBox");
	}
}
