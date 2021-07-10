#include "pch.h"
#include "HorizontalTrackbarControl.h"

using namespace std;

namespace gui_framework
{
	HorizontalTrackbarControl::HorizontalTrackbarControl(const wstring& trackbarName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent, bool autoTicks, horizontalTickPosition position, bool selectionRange, bool noTicks) :
		BaseTrackbarControl
		(
			trackbarName,
			utility::ComponentSettings
			(
				TBS_HORZ | (position == horizontalTickPosition::bottom ? TBS_BOTTOM : (position == horizontalTickPosition::top ? TBS_TOP : TBS_BOTH)),
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
