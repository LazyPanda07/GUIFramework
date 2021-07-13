#include "pch.h"
#include "InfiniteProgressBar.h"

using namespace std;

namespace gui_framework
{
	InfiniteProgressBar::InfiniteProgressBar(const wstring& progressBarName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent, int animationPeriod) :
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
		),
		IResizableComponent
		(
			handle,
			parent->getHandle()
		)
	{

	}
}
