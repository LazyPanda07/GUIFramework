#include "pch.h"
#include "ProgressBar.h"

using namespace std;

namespace gui_framework
{
	ProgressBar::ProgressBar(const wstring& progressBarName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent) :
		BaseComponent
		(
			wstring(standard_classes::progressBar),
			progressBarName,
			utility::ComponentSettings
			(
				NULL,
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
				NULL,
				x,
				y,
				width,
				height
			),
			parent
		),
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
			parent
		)
	{

	}
}
