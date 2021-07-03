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

		uint16_t ImagesHolder::addImage(const filesystem::path& pathToImage)
		{
			return BaseLoadableHolder::insertImage(pathToImage, imageType::bitmap);
		}
	}
}
