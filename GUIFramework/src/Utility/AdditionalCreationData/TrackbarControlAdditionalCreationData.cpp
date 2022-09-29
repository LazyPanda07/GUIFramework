#include "core.h"
#include "TrackbarControlAdditionalCreationData.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		AdditionalCreationData<HorizontalTrackbarControl>::AdditionalCreationData(bool autoTicks, HorizontalTrackbarControl::horizontalTickPosition position, bool selectionRange, bool noTicks) :
			autoTicks(autoTicks),
			position(position),
			selectionRange(selectionRange),
			noTicks(noTicks)
		{

		}

		any AdditionalCreationData<HorizontalTrackbarControl>::getData() const
		{
			return make_any<tuple<bool, HorizontalTrackbarControl::horizontalTickPosition, bool, bool>>(autoTicks, position, selectionRange, noTicks);
		}

		AdditionalCreationData<VerticalTrackbarControl>::AdditionalCreationData(bool autoTicks, VerticalTrackbarControl::verticalTickPosition position, bool selectionRange, bool noTicks) :
			autoTicks(autoTicks),
			position(position),
			selectionRange(selectionRange),
			noTicks(noTicks)
		{

		}

		any AdditionalCreationData<VerticalTrackbarControl>::getData() const
		{
			return make_any<tuple<bool, VerticalTrackbarControl::verticalTickPosition, bool, bool>>(autoTicks, position, selectionRange, noTicks);
		}
	}
}
