#include "pch.h"
#include "InfiniteProgressBar.h"

using namespace std;

namespace gui_framework
{
	InfiniteProgressBar::InfiniteProgressBar(const wstring& progressBarName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent, int animationPeriod) :
		BaseComponent
		(
			wstring(standard_classes::progressBar),
			progressBarName,
			utility::ComponentSettings
			(
				PBS_MARQUEE,
				x,
				y,
				width,
				height
			),
			parent
		),
		BaseResizableComponent
		(
			wstring(standard_classes::progressBar),
			progressBarName,
			utility::ComponentSettings
			(
				PBS_MARQUEE,
				x,
				y,
				width,
				height
			),
			parent
		),
		BaseInfiniteProgressBar
		(
			progressBarName,
			utility::ComponentSettings
			(
				NULL,
				x,
				y,
				width,
				height
			),
			parent,
			animationPeriod
		)
	{

	}
}
