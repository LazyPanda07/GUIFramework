#include "Core.h"
#include "TrackbarControlStyles.h"

using namespace std;

namespace gui_framework
{
	namespace styles
	{
		TrackbarControlStyles::TrackbarControlStyles(const TrackbarControlStyles& buttonStyles)
		{
			this->appendStyle(buttonStyles.getStyles());

			this->appendExtendedStyle(buttonStyles.getExtendedStyles());
		}
	}
}
