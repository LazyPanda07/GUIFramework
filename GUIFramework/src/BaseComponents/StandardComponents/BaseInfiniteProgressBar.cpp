#include "pch.h"
#include "BaseInfiniteProgressBar.h"

using namespace std;

namespace gui_framework
{
	BaseInfiniteProgressBar::BaseInfiniteProgressBar(const wstring& progressBarName, const utility::ComponentSettings& settings, BaseComponent* parent) :
		BaseComponent
		(
			wstring(standard_classes::progressBar),
			progressBarName,
			utility::ComponentSettings
			(
				settings.styles | PBS_MARQUEE,
				settings.x,
				settings.y,
				settings.width,
				settings.height,
				settings.extendedStyles
			),
			parent
		)
	{

	}
}
