#include "pch.h"
#include "ProgressBar.h"

using namespace std;

namespace gui_framework
{
	ProgressBar::ProgressBar(const wstring& progressBarName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent, int minRange, int maxRange, int updateStep) :
		BaseProgressBar
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
			minRange,
			maxRange,
			updateStep
		),
		IResizableComponent
		(
			handle,
			parent->getHandle()
		)
	{

	}
}
