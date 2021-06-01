#include "pch.h"
#include "ComponentSettings.h"

namespace gui_framework
{
	namespace utility
	{
		ComponentSettings::ComponentSettings(DWORD styles, int x, int y, int width, int height, DWORD extendedStyles) :
			extendedStyles(extendedStyles),
			styles(styles),
			x(x),
			y(y),
			width(width),
			height(height)
		{

		}
	}
}
