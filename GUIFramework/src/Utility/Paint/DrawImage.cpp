#include "pch.h"
#include "DrawImage.h"

using namespace std;

template<typename T>
bool drawImageImplementation(const gui_framework::BaseWindow* window, const gui_framework::utility::BaseLoadableHolder& holder, int x, int y, const T& index);

namespace gui_framework
{
	namespace utility
	{
		namespace paint
		{
			bool drawImage(const BaseWindow* window, const BaseLoadableHolder& holder, int x, int y, uint16_t index)
			{
				return drawImageImplementation(window, holder, x, y, index);
			}

			bool drawImage(const BaseWindow* window, const BaseLoadableHolder& holder, int x, int y, const std::filesystem::path& pathToImage)
			{
				return drawImageImplementation(window, holder, x, y, pathToImage);
			}
		}
	}
}

template<typename T>
bool drawImageImplementation(const gui_framework::BaseWindow* window, const gui_framework::utility::BaseLoadableHolder& holder, int x, int y, const T& index)
{
	PAINTSTRUCT paint = {};
	HDC deviceContext = BeginPaint(window->getHandle(), &paint);
	bool result = false;

	if constexpr (is_same_v<T, uint16_t>)
	{
		result = ImageList_Draw(holder.getImageList(), index, deviceContext, x, y, ILD_TRANSPARENT);
	}
	else
	{
		result = ImageList_Draw(holder.getImageList(), holder.getImageIndex(index), deviceContext, x, y, ILD_TRANSPARENT);
	}
	
	EndPaint(window->getHandle(), &paint);

	return result;
}
