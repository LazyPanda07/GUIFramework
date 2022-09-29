#include "core.h"
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
			const any* result = nullptr;

			for (const auto& [path, data] : images)
			{
				if (data.index == iconIndex)
				{
					result = &data.data;
				}
			}

			if (!result)
			{
				throw out_of_range("Wrong index");
			}

			return any_cast<HICON>(*result);
		}

		uint16_t IconsHolder::addImage(const filesystem::path& pathToIcon)
		{
			return BaseLoadableHolder::insertImage(pathToIcon, imageType::icon);
		}
	}
}
