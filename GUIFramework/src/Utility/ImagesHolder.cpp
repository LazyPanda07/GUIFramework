#include "pch.h"
#include "ImagesHolder.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		ImagesHolder::imageData::imageData(uint16_t index, imageType type) :
			index(index),
			type(type)
		{

		}

		ImagesHolder::ImagesHolder(uint16_t imagesWidth, uint16_t imagesHeight, size_t count) :
			imageList(ImageList_Create(imagesWidth, imagesHeight, ILC_COLOR32, 0, static_cast<int>(count))),
			imagesWidth(imagesWidth),
			imagesHeight(imagesHeight)
		{

		}

		uint16_t ImagesHolder::addImage(const filesystem::path& pathToImage, imageType type)
		{
			HBITMAP image = static_cast<HBITMAP>(LoadImageW(nullptr, pathToImage.wstring().data(), static_cast<uint32_t>(type), imagesWidth, imagesHeight, LR_LOADFROMFILE));

			return images.emplace(pathToImage, imageData(ImageList_Add(imageList, image, NULL), type)).first->second.index;
		}

		void ImagesHolder::removeImage(const filesystem::path& pathToImage)
		{
			images.erase(pathToImage);
		}

		void ImagesHolder::removeImage(uint16_t imageIndex)
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

		bool ImagesHolder::contains(const filesystem::path& pathToImage) const
		{
			return images.contains(pathToImage);
		}

		uint16_t ImagesHolder::getImagesWidth() const
		{
			return imagesWidth;
		}

		uint16_t ImagesHolder::getImagesHeight() const
		{
			return imagesHeight;
		}

		uint16_t ImagesHolder::getImageIndex(const filesystem::path& pathToImage) const
		{
			return images.at(pathToImage).index;
		}

		ImagesHolder::imageType ImagesHolder::getImageType(const filesystem::path& pathToImage) const
		{
			return images.at(pathToImage).type;
		}

		ImagesHolder::imageType ImagesHolder::getImageType(uint16_t imageIndex) const
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

		HIMAGELIST ImagesHolder::getImageList() const
		{
			return imageList;
		}

		uint16_t ImagesHolder::operator [] (const filesystem::path& pathToImage) const
		{
			return images.at(pathToImage).index;
		}

		ImagesHolder::~ImagesHolder()
		{
			ImageList_Destroy(imageList);
		}
	}
}
