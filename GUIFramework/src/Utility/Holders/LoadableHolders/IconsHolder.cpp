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

		HICON IconsHolder::getIcon(const filesystem::path& pathToIcon) const
		{
			return any_cast<HICON>(images.at(pathToIcon).data);
		}

		HICON IconsHolder::getIcon(uint16_t iconIndex) const
		{
			return any_cast<HICON>(ranges::find_if(images, [iconIndex](const pair<wstring, imageData>& data) { return data.second.index == iconIndex; })->second.data);
		}

		uint16_t IconsHolder::addImage(const filesystem::path& pathToIcon)
		{
			return BaseLoadableHolder::insertImage(pathToIcon, imageType::icon);
		}
	}
}
