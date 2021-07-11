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
			bool drawImageByIndex(const BaseWindow* window, const BaseLoadableHolder& holder, int x, int y, uint16_t index)
			{
				return drawImageImplementation(window, holder, x, y, index);
			}

			bool drawImageByPath(const BaseWindow* window, const BaseLoadableHolder& holder, int x, int y, const filesystem::path& pathToImage)
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
	HWND handle = window->getHandle();
	HDC deviceContext = BeginPaint(handle, &paint);
	bool result = false;

	if constexpr (is_same_v<T, uint16_t>)
	{
		result = ImageList_Draw(holder.getImageList(), index, deviceContext, x, y, ILD_TRANSPARENT);
	}
	else
	{
		result = ImageList_Draw(holder.getImageList(), holder.getImageIndex(index), deviceContext, x, y, ILD_TRANSPARENT);
	}

	ReleaseDC(handle, deviceContext);

	EndPaint(handle, &paint);

	return result;
}
