#include "pch.h"
#include "ImagesHolder.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		ImagesHolder::ImagesHolder(uint16_t imagesWidth, uint16_t imagesHeight, size_t count) :
			BaseLoadableHolder
			(
				imagesWidth,
				imagesHeight,
				count
			)
		{

		}

		HBITMAP ImagesHolder::getImage(const filesystem::path& pathToImage) const
		{
			return any_cast<HBITMAP>(images.at(pathToImage).data);
		}

		HBITMAP ImagesHolder::getImage(uint16_t imageIndex) const
		{
			return any_cast<HBITMAP>(ranges::find_if(images, [imageIndex](const pair<wstring, imageData>& data) { return data.second.index == imageIndex; })->second.data);
		}

		uint16_t ImagesHolder::addImage(const filesystem::path& pathToImage)
		{
			return BaseLoadableHolder::insertImage(pathToImage, imageType::bitmap);
		}
	}
}
