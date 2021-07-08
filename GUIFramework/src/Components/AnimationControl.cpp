#include "pch.h"
#include "AnimationControl.h"

using namespace std;

namespace gui_framework
{
	AnimationControl::AnimationControl(const std::wstring& animationControlName, int x, int y, uint16_t width, uint16_t height, BaseComponent* parent, bool isCentered, bool isAutoPlay) :
		BaseComponent
		(
			wstring(standard_classes::animateControl),
			animationControlName,
			utility::ComponentSettings
			(
				NULL,
				x,
				y,
				width,
				height,
				NULL
			),
			parent
		),
		BaseAnimationControl
		(
			animationControlName,
			utility::ComponentSettings
			(
				NULL,
				x,
				y,
				width,
				height,
				NULL
			),
			parent,
			isCentered,
			isAutoPlay
		)
	{

	}
}
