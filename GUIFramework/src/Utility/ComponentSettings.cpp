#include "pch.h"
#include "ComponentSettings.h"

namespace gui_framework
{
	namespace utility
	{
		ComponentSettings::ComponentSettings(DWORD styles, int x, int y, uint16_t width, uint16_t height, DWORD extendedStyles) :
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
