#include "pch.h"
#include "VerticalTrackbarControl.h"

#include "Styles/Components/Trackbars/VerticalTrackbarControlStyles.h"

using namespace std;

namespace gui_framework
{
	VerticalTrackbarControl::VerticalTrackbarControl(const wstring& trackbarName, const utility::ComponentSettings& settings, BaseComponent* parent, bool autoTicks, verticalTickPosition position, bool selectionRange, bool noTicks) :
		BaseTrackbarControl
		(
			trackbarName,
			settings,
			styles::VerticalTrackbarControlStyles(position),
			parent
		)
	{
		if (autoTicks)
		{
			utility::appendStyle(handle, TBS_AUTOTICKS);
		}

		if (selectionRange)
		{
			utility::appendStyle(handle, TBS_ENABLESELRANGE);
		}

		if (noTicks)
		{
			utility::appendStyle(handle, TBS_NOTICKS);
		}
	}

	json::JSONBuilder VerticalTrackbarControl::getStructure() const
	{
		using json::utility::objectSmartPointer;
		using json::utility::jsonObject;

		json::JSONBuilder builder = BaseTrackbarControl::getStructure();
		objectSmartPointer<jsonObject>& current = get<objectSmartPointer<jsonObject>>(builder[utility::to_string(windowName, ISerializable::getCodepage())]);

		__utility::changeClassName(current, serialized_classes::verticalTrackbarControl);

		return builder;
	}
}
