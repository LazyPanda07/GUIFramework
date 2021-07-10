#include "pch.h"
#include "VerticalTrackbarControl.h"

using namespace std;

namespace gui_framework
{
	VerticalTrackbarControl::VerticalTrackbarControl(const wstring& trackbarName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent, bool autoTicks, verticalTickPosition position, bool selectionRange, bool noTicks) :
		BaseTrackbarControl
		(
			trackbarName,
			utility::ComponentSettings
			(
				TBS_VERT | (position == verticalTickPosition::left ? TBS_LEFT : (position == verticalTickPosition::right ? TBS_RIGHT : TBS_BOTH)),
				x,
				y,
				width,
				height
			),
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
}
