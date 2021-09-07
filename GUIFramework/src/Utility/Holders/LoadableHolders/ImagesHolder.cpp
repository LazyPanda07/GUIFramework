#include "headers.h"
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
			const any* result = nullptr;

			for (const auto& [path, data] : images)
			{
				if (data.index == imageIndex)
				{
					result = &data.data;
				}
			}

			if (!result)
			{
				throw out_of_range("Wrong index");
			}

			return any_cast<HBITMAP>(*result);
		}

		uint16_t ImagesHolder::addImage(const filesystem::path& pathToImage)
		{
			return BaseLoadableHolder::insertImage(pathToImage, imageType::bitmap);
		}
	}
}
