#include "pch.h"
#include "ImageButton.h"

#include "Styles/Components/Buttons/DefaultButtonStyles.h"
#include "Utility/Holders/LoadableHolders/BaseLoadableHolder.h"

using namespace std;

namespace gui_framework
{
	void ImageButton::drawImage()
	{
		if (!pathToImage.empty())
		{
			int imageType;
			HANDLE imageHandle;

			if (pathToImage.extension() == ".ico")
			{
				utility::appendStyle(handle, BS_ICON);

				imageHandle = LoadImageW(nullptr, pathToImage.wstring().data(), static_cast<uint32_t>(utility::BaseLoadableHolder::imageType::icon), imageWidth, imageHeight, LR_LOADFROMFILE);

				image = static_cast<HICON>(imageHandle);

				imageType = IMAGE_ICON;
			}
			else
			{
				utility::appendStyle(handle, BS_BITMAP);

				imageHandle = LoadImageW(nullptr, pathToImage.wstring().data(), static_cast<uint32_t>(utility::BaseLoadableHolder::imageType::bitmap), imageWidth, imageHeight, LR_LOADFROMFILE);

				image = static_cast<HBITMAP>(imageHandle);

				imageType = IMAGE_BITMAP;
			}

			switch (type)
			{
			case gui_framework::ImageButton::drawingType::image:
				SendMessageW(handle, BM_SETIMAGE, imageType, reinterpret_cast<LPARAM>(imageHandle));

				break;

			case gui_framework::ImageButton::drawingType::text:
				utility::removeStyle(handle, imageType == IMAGE_ICON ? BS_ICON : BS_BITMAP);

				break;

			case gui_framework::ImageButton::drawingType::textAndImage:
				utility::removeStyle(handle, imageType == IMAGE_ICON ? BS_ICON : BS_BITMAP);

				SendMessageW(handle, BM_SETIMAGE, imageType, reinterpret_cast<LPARAM>(imageHandle));

				break;

			default:
				break;
			}
		}
	}

	ImageButton::ImageButton(const wstring& buttonName, const filesystem::path& pathToImage, drawingType type, uint16_t imageWidth, uint16_t imageHeight, int x, int y, BaseComponent* parent, const function<void()>& onClick, uint16_t width, uint16_t height) :
		BaseButton
		(
			buttonName,
			L"",
			utility::ComponentSettings
			(
				x,
				y,
				width,
				height
			),
			styles::DefaultButtonStyles(),
			parent,
			onClick
		),
		IResizableComponent
		(
			handle,
			parent->getHandle()
		),
		pathToImage(pathToImage),
		imageWidth(imageWidth),
		imageHeight(imageHeight),
		type(type)
	{
		this->drawImage();
	}

	ImageButton::ImageButton(const wstring& buttonName, const filesystem::path& pathToImage, drawingType type, uint16_t imageWidth, uint16_t imageHeight, int x, int y, BaseComponent* parent, const string& functionName, const string& moduleName, uint16_t width, uint16_t height) :
		BaseButton
		(
			buttonName,
			L"",
			utility::ComponentSettings
			(
				x,
				y,
				width,
				height
			),
			styles::DefaultButtonStyles(),
			parent,
			functionName,
			moduleName
		),
		IResizableComponent
		(
			handle,
			parent->getHandle()
		),
		pathToImage(pathToImage),
		imageWidth(imageWidth),
		imageHeight(imageHeight),
		type(type)
	{
		this->drawImage();
	}
}
