#include "core.h"
#include "HorizontalTrackbarControl.h"

#include "Styles/Components/Trackbars/HorizontalTrackbarControlStyles.h"

using namespace std;

namespace gui_framework
{
	HorizontalTrackbarControl::HorizontalTrackbarControl(const wstring& trackbarName, const utility::ComponentSettings& settings, BaseComponent* parent, bool autoTicks, horizontalTickPosition position, bool selectionRange, bool noTicks) :
		BaseTrackbarControl
		(
			trackbarName,
			settings,
			styles::HorizontalTrackbarControlStyles(position),
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

	size_t HorizontalTrackbarControl::getHash() const
	{
		return typeid(HorizontalTrackbarControl).hash_code();
	}

	json::JSONBuilder HorizontalTrackbarControl::getStructure() const
	{
		using json::utility::jsonObject;

		json::JSONBuilder builder = BaseTrackbarControl::getStructure();
		jsonObject& current = get<jsonObject>(builder[utility::to_string(windowName, ISerializable::getCodepage())]);

		return builder;
	}
}
