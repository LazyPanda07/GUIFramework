#include "pch.h"
#include "BaseTrackbarControl.h"

using namespace std;

namespace gui_framework
{
	BaseTrackbarControl::BaseTrackbarControl(const wstring& trackbarName, const utility::ComponentSettings& settings, BaseComponent* parent) :
		BaseComponent
		(
			wstring(standard_classes::trackbarControl),
			trackbarName,
			settings,
			parent
		)
	{

	}
}
