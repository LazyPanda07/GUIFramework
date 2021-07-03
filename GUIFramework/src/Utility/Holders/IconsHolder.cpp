#include "pch.h"
#include "IconsHolder.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		IconsHolder::IconsHolder(uint16_t imagesWidth, uint16_t imagesHeight, size_t count) :
			BaseLoadableHolder
			(
				imagesWidth,
				imagesHeight,
				count
			)
		{

		}

		uint16_t IconsHolder::addImage(const filesystem::path& pathToImage)
		{
			return BaseLoadableHolder::insertImage(pathToImage, imageType::bitmap);
		}
	}
}
