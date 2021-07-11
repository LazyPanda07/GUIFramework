#include "pch.h"
#include "DrawImage.h"

using namespace std;

template<typename T>
bool drawImageImplementation(const gui_framework::BaseWindow* window, const gui_framework::utility::BaseLoadableHolder& holder, int x, int y, const T& index, uint16_t width, uint16_t height);

namespace gui_framework
{
	namespace utility
	{
		namespace paint
		{
			bool drawImage(const BaseWindow* window, const BaseLoadableHolder& holder, int x, int y, uint16_t index, uint16_t width, uint16_t height)
			{
				return drawImageImplementation(window, holder, x, y, index, width, height);
			}

			bool drawImage(const BaseWindow* window, const BaseLoadableHolder& holder, int x, int y, const std::filesystem::path& pathToImage, uint16_t width, uint16_t height)
			{
				return drawImageImplementation(window, holder, x, y, pathToImage, width, height);
			}
		}
	}
}

template<typename T>
bool drawImageImplementation(const gui_framework::BaseWindow* window, const gui_framework::utility::BaseLoadableHolder& holder, int x, int y, const T& index, uint16_t width, uint16_t height)
{
	PAINTSTRUCT paint = {};
	HDC deviceContext = BeginPaint(window->getHandle(), &paint);
	bool result = false;

	if constexpr (is_same_v<T, uint16_t>)
	{
		result = ImageList_DrawEx(holder.getImageList(), index, deviceContext, x, y, width, height, CLR_DEFAULT, CLR_DEFAULT, ILD_TRANSPARENT);
	}
	else
	{
		result = ImageList_DrawEx(holder.getImageList(), holder.getImageIndex(index), deviceContext, x, y, width, height, CLR_DEFAULT, CLR_DEFAULT, ILD_TRANSPARENT);
	}

	ReleaseDC(window->getHandle(), deviceContext);
	EndPaint(window->getHandle(), &paint);

	return result;
}
