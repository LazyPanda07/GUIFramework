#include "HorizontalTrackbarControlCreator.h"

#include "Components/Trackbars/HorizontalTrackbarControl.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		BaseComponent* HorizontalTrackbarControlCreator::create(const wstring& windowName, const utility::ComponentSettings& settings, const any& additionalData, BaseComposite* parent)
		{
			auto [autoTicks, position, selectionRange, noTicks] = any_cast<tuple<bool, HorizontalTrackbarControl::horizontalTickPosition, bool, bool>>(additionalData);

			return new HorizontalTrackbarControl(windowName, settings, parent, autoTicks, position, selectionRange, noTicks);
		}
	}
}
