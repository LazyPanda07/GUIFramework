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
	IMAGEINFO info = {};
	bool result = false;

	if constexpr (is_same_v<T, uint16_t>)
	{
		ImageList_GetImageInfo(holder.getImageList(), index, &info);
	}
	else
	{
		ImageList_GetImageInfo(holder.getImageList(), holder.getImageIndex(index), &info);
	}

	result = DrawStateW(deviceContext, NULL, nullptr, reinterpret_cast<LPARAM>(info.hbmImage), NULL, x, y, holder.getImagesWidth(), holder.getImagesHeight(), DST_BITMAP | DSS_NORMAL);

	ReleaseDC(handle, deviceContext);

	EndPaint(handle, &paint);

	return result;
}
