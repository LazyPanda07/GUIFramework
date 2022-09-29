#include "core.h"
#include "Draw.h"

using namespace std;

template<typename T>
bool drawImplementation(const gui_framework::BaseWindow* window, const gui_framework::utility::BaseLoadableHolder& holder, int x, int y, const T& index);

namespace gui_framework
{
	namespace utility
	{
		namespace paint
		{
			GUI_FRAMEWORK_API_FUNCTION bool drawImageByIndex(const BaseWindow* window, const ImagesHolder& holder, int x, int y, uint16_t index)
			{
				return drawImplementation(window, holder, x, y, index);
			}

			GUI_FRAMEWORK_API_FUNCTION bool drawImageByPath(const BaseWindow* window, const ImagesHolder& holder, int x, int y, const filesystem::path& pathToImage)
			{
				return drawImplementation(window, holder, x, y, pathToImage);
			}

			GUI_FRAMEWORK_API_FUNCTION bool drawIconByIndex(const BaseWindow* window, const IconsHolder& holder, int x, int y, uint16_t index)
			{
				return drawImplementation(window, holder, x, y, index);
			}

			GUI_FRAMEWORK_API_FUNCTION bool drawIconByPath(const BaseWindow* window, const IconsHolder& holder, int x, int y, const filesystem::path& pathToImage)
			{
				return drawImplementation(window, holder, x, y, pathToImage);
			}
		}
	}
}

template<typename T>
bool drawImplementation(const gui_framework::BaseWindow* window, const gui_framework::utility::BaseLoadableHolder& holder, int x, int y, const T& index)
{
	PAINTSTRUCT paint = {};
	HWND handle = window->getHandle();
	HDC deviceContext = BeginPaint(handle, &paint);
	LPARAM drawData = NULL;
	uint32_t flags = DSS_NORMAL;
	bool result = false;
	
	try
	{
		const gui_framework::utility::ImagesHolder& imagesHolder = dynamic_cast<const gui_framework::utility::ImagesHolder&>(holder);

		drawData = reinterpret_cast<LPARAM>(imagesHolder.getImage(index));

		flags |= DST_BITMAP;
	}
	catch (const bad_cast&)
	{
		const gui_framework::utility::IconsHolder& iconsHolder = dynamic_cast<const gui_framework::utility::IconsHolder&>(holder);

		drawData = reinterpret_cast<LPARAM>(iconsHolder.getIcon(index));

		flags |= DST_ICON;
	}

	result = DrawStateW(deviceContext, NULL, nullptr, drawData, NULL, x, y, holder.getImagesWidth(), holder.getImagesHeight(), flags);

	ReleaseDC(handle, deviceContext);

	EndPaint(handle, &paint);

	return result;
}
