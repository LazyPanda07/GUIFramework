#include "headers.h"
#include "ComponentSettings.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		ComponentSettings::ComponentSettings(int x, int y, uint16_t width, uint16_t height, const vector<string>& localizationKeys) :
			x(x),
			y(y),
			width(width),
			height(height),
			localizationKeys(localizationKeys)
		{

		}
	}
}
