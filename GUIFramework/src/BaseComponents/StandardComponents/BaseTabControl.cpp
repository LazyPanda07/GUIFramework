#include "pch.h"
#include "BaseTabControl.h"

#include "Exceptions/FileDoesNotExist.h"

using namespace std;

namespace gui_framework
{
	BaseTabControl::BaseTabControl(const wstring& tabControlName, const utility::ComponentSettings& settings, BaseComponent* parent) :
		BaseComponent
		(
			wstring(standard_classes::tabControl),
			tabControlName,
			settings,
			parent
		),
		imageList(ImageList_Create(standard_sizes::defaultTabControlImageWidth, standard_sizes::defaultTabControlImageHeight, ILC_COLOR32, 0, standard_sizes::defaultImagesCount))
	{
		SendMessageW(handle, TCM_SETIMAGELIST, NULL, reinterpret_cast<LPARAM>(handle));
	}

	LRESULT BaseTabControl::append(const wstring& text)
	{
		size_t currentSize = this->size();
		TCITEMW item = {};

		item.pszText = const_cast<wchar_t*>(text.data());
		item.cchTextMax = static_cast<int>(text.size());
		item.iImage = -1;

		return SendMessageW(handle, TCM_INSERTITEM, currentSize, reinterpret_cast<LPARAM>(&item));
	}

	LRESULT BaseTabControl::append(const filesystem::path& pathToImage)
	{
		if (!filesystem::exists(pathToImage))
		{
			throw exceptions::FileDoesNotExist(pathToImage);
		}

		size_t currentSize = this->size();
		TCITEMW item = {};

		if (!images.contains(pathToImage))
		{
			HBITMAP image = static_cast<HBITMAP>(LoadImageW(nullptr, pathToImage.wstring().data(), IMAGE_BITMAP, standard_sizes::defaultTabControlImageWidth, standard_sizes::defaultTabControlImageHeight, LR_LOADFROMFILE));

			images[pathToImage] = ImageList_Add(imageList, image, NULL);
		}

		item.iImage = images[pathToImage];

		return SendMessageW(handle, TCM_INSERTITEM, currentSize, reinterpret_cast<LPARAM>(&item));
	}

	LRESULT BaseTabControl::append(const wstring& text, const filesystem::path& pathToImage)
	{
		if (!filesystem::exists(pathToImage))
		{
			throw exceptions::FileDoesNotExist(pathToImage);
		}

		size_t currentSize = this->size();
		TCITEMW item = {};

		if (!images.contains(pathToImage))
		{
			HBITMAP image = static_cast<HBITMAP>(LoadImageW(nullptr, pathToImage.wstring().data(), IMAGE_BITMAP, standard_sizes::defaultTabControlImageWidth, standard_sizes::defaultTabControlImageHeight, LR_LOADFROMFILE));

			images[pathToImage] = ImageList_Add(imageList, image, NULL);
		}

		item.pszText = const_cast<wchar_t*>(text.data());
		item.cchTextMax = static_cast<int>(text.size());
		item.iImage = images[pathToImage];

		return SendMessageW(handle, TCM_INSERTITEM, currentSize, reinterpret_cast<LPARAM>(&item));
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
