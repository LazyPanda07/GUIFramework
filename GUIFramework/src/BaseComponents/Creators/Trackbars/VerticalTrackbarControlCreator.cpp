#include "pch.h"
#include "VerticalTrackbarControlCreator.h"

#include "Components/Trackbars/VerticalTrackbarControl.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		BaseComponent* VerticalTrackbarControlCreator::create(const wstring& windowName, const utility::ComponentSettings& settings, const any& additionalData, BaseComponent* parent)
		{
			auto [autoTicks, position, selectionRange, noTicks] = any_cast<tuple<bool, VerticalTrackbarControl::verticalTickPosition, bool, bool>>(additionalData);

			return new VerticalTrackbarControl(windowName, settings.x, settings.y, settings.width, settings.height, parent, autoTicks, position, selectionRange, noTicks);
		}
	}
}
