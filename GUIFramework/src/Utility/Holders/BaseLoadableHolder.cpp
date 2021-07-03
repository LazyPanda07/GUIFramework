#include "pch.h"
#include "BaseLoadableHolder.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		BaseLoadableHolder::imageData::imageData(uint16_t index, imageType type) :
			index(index),
			type(type)
		{

		}

		BaseLoadableHolder::BaseLoadableHolder(uint16_t imagesWidth, uint16_t imagesHeight, size_t count) :
			imageList(ImageList_Create(imagesWidth, imagesHeight, ILC_COLOR32, 0, static_cast<int>(count))),
			imagesWidth(imagesWidth),
			imagesHeight(imagesHeight)
		{

		}

		uint16_t BaseLoadableHolder::insertImage(const filesystem::path& pathToImage, imageType type)
		{
			HBITMAP image = static_cast<HBITMAP>(LoadImageW(nullptr, pathToImage.wstring().data(), static_cast<uint32_t>(type), imagesWidth, imagesHeight, LR_LOADFROMFILE));
			uint16_t resultIndex = images.emplace(pathToImage, imageData(ImageList_Add(imageList, image, NULL), type)).first->second.index;

			switch (type)
			{
			case imageType::bitmap:
				DeleteObject(image);

				break;
			case imageType::icon:
				DestroyIcon(reinterpret_cast<HICON>(image));

				break;
			case imageType::cursor:
				DestroyCursor(reinterpret_cast<HCURSOR>(image));

				break;

			default:
				break;
			}

			return resultIndex;
		}

		void BaseLoadableHolder::removeImage(const filesystem::path& pathToImage)
		{
			images.erase(pathToImage);
		}

		void BaseLoadableHolder::removeImage(uint16_t imageIndex)
		{
			for (const auto& [key, value] : images)
			{
				if (value.index == imageIndex)
				{
					images.erase(key);

					break;
				}
			}
		}

		bool BaseLoadableHolder::contains(const filesystem::path& pathToImage) const
		{
			return images.contains(pathToImage);
		}

		uint16_t BaseLoadableHolder::getImagesWidth() const
		{
			return imagesWidth;
		}

		uint16_t BaseLoadableHolder::getImagesHeight() const
		{
			return imagesHeight;
		}

		uint16_t BaseLoadableHolder::getImageIndex(const filesystem::path& pathToImage) const
		{
			return images.at(pathToImage).index;
		}

		BaseLoadableHolder::imageType BaseLoadableHolder::getImageType(const filesystem::path& pathToImage) const
		{
			return images.at(pathToImage).type;
		}

		BaseLoadableHolder::imageType BaseLoadableHolder::getImageType(uint16_t imageIndex) const
		{
			for (const auto& [key, value] : images)
			{
				if (value.index == imageIndex)
				{
					return value.type;
				}
			}

			throw out_of_range(format("Can't find imageType at {} index", imageIndex));
		}

		HIMAGELIST BaseLoadableHolder::getImageList() const
		{
			return imageList;
		}

		uint16_t BaseLoadableHolder::operator [] (const filesystem::path& pathToImage) const
		{
			return images.at(pathToImage).index;
		}

		BaseLoadableHolder::~BaseLoadableHolder()
		{
			ImageList_Destroy(imageList);
		}
	}
}
