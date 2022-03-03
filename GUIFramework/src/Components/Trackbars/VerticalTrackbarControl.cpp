#include "headers.h"
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

	size_t VerticalTrackbarControl::getHash() const
	{
		return typeid(VerticalTrackbarControl).hash_code();
	}

	json::JSONBuilder VerticalTrackbarControl::getStructure() const
	{
		using json::utility::jsonObject;

		json::JSONBuilder builder = BaseTrackbarControl::getStructure();
		jsonObject& current = get<jsonObject>(builder[utility::to_string(windowName, ISerializable::getCodepage())]);

		return builder;
	}
}
