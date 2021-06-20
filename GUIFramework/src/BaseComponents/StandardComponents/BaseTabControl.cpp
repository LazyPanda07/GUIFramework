#include "pch.h"
#include "BaseTabControl.h"

#include "Exceptions/FileDoesNotExist.h"

using namespace std;

namespace gui_framework
{
	BaseTabControl::BaseTabControl(const wstring& tabControlName, const utility::ComponentSettings& settings, uint16_t iconWidth, uint16_t iconHeight, BaseComponent* parent) :
		BaseComponent
		(
			wstring(standard_classes::tabControl),
			tabControlName,
			settings,
			parent
		),
		imageList(ImageList_Create(iconWidth, iconHeight, ILC_COLOR32, 0, standard_sizes::defaultImagesCount)),
		iconWidth(iconWidth),
		iconHeight(iconHeight)
	{
		SendMessageW(handle, TCM_SETIMAGELIST, NULL, reinterpret_cast<LPARAM>(imageList));
	}

	LRESULT BaseTabControl::appendText(const wstring& text)
	{
		return this->insertText(this->size(), text);
	}

	LRESULT BaseTabControl::insertText(size_t index, const wstring& text)
	{
		TCITEMW item = {};

		item.mask = TCIF_TEXT;
		item.pszText = const_cast<wchar_t*>(text.data());
		item.cchTextMax = static_cast<int>(text.size());

		return SendMessageW(handle, TCM_INSERTITEM, index, reinterpret_cast<LPARAM>(&item));
	}

	LRESULT BaseTabControl::appendImage(const filesystem::path& pathToImage)
	{
		return this->insertImage(this->size(), pathToImage);
	}

	LRESULT BaseTabControl::insertImage(size_t index, const filesystem::path& pathToImage)
	{
		if (!filesystem::exists(pathToImage))
		{
			throw exceptions::FileDoesNotExist(pathToImage);
		}

		TCITEMW item = {};

		if (!images.contains(pathToImage))
		{
			HBITMAP image = static_cast<HBITMAP>(LoadImageW(nullptr, pathToImage.wstring().data(), IMAGE_BITMAP, iconWidth, iconHeight, LR_LOADFROMFILE));

			images[pathToImage] = ImageList_Add(imageList, image, NULL);
		}

		item.mask = TCIF_IMAGE;
		item.iImage = images[pathToImage];

		return SendMessageW(handle, TCM_INSERTITEM, index, reinterpret_cast<LPARAM>(&item));
	}

	LRESULT BaseTabControl::appendTextAndImage(const wstring& text, const filesystem::path& pathToImage)
	{
		return this->insertTextAndImage(this->size(), text, pathToImage);
	}

	LRESULT BaseTabControl::insertTextAndImage(size_t index, const wstring& text, const filesystem::path& pathToImage)
	{
		if (!filesystem::exists(pathToImage))
		{
			throw exceptions::FileDoesNotExist(pathToImage);
		}

		TCITEMW item = {};

		if (!images.contains(pathToImage))
		{
			HBITMAP image = static_cast<HBITMAP>(LoadImageW(nullptr, pathToImage.wstring().data(), IMAGE_BITMAP, iconWidth, iconHeight, LR_LOADFROMFILE));

			images[pathToImage] = ImageList_Add(imageList, image, NULL);
		}

		item.mask = TCIF_TEXT | TCIF_IMAGE;
		item.pszText = const_cast<wchar_t*>(text.data());
		item.cchTextMax = static_cast<int>(text.size());
		item.iImage = images[pathToImage];

		return SendMessageW(handle, TCM_INSERTITEM, index, reinterpret_cast<LPARAM>(&item));
	}

	bool BaseTabControl::setItem(size_t index, const wstring& text, const filesystem::path& pathToImage)
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
				HBITMAP image = static_cast<HBITMAP>(LoadImageW(nullptr, pathToImage.wstring().data(), IMAGE_BITMAP, iconWidth, iconHeight, LR_LOADFROMFILE));

				images[pathToImage] = ImageList_Add(imageList, image, NULL);
			}

			item.mask |= TCIF_IMAGE;

			item.iImage = images[pathToImage];
		}

		return SendMessageW(handle, TCM_SETITEM, index, reinterpret_cast<LPARAM>(&item));
	}

	TCITEMW BaseTabControl::getItem(size_t index)
	{
		TCITEMW item = {};

		SendMessageW(handle, TCM_GETITEM, static_cast<WPARAM>(index), reinterpret_cast<LPARAM>(&item));

		return item;
	}

	bool BaseTabControl::removeTab(size_t index)
	{
		return SendMessageW(handle, TCM_DELETEITEM, static_cast<WPARAM>(index), NULL);
	}

	bool BaseTabControl::clear()
	{
		return SendMessageW(handle, TCM_DELETEALLITEMS, NULL, NULL);
	}

	size_t BaseTabControl::size() const
	{
		return SendMessageW(handle, TCM_GETITEMCOUNT, NULL, NULL);
	}

	BaseTabControl::~BaseTabControl()
	{
		ImageList_Destroy(imageList);
	}
}
