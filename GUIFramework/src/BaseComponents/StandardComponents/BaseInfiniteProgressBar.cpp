#include "pch.h"
#include "BaseInfiniteProgressBar.h"

using namespace std;

namespace gui_framework
{
	BaseInfiniteProgressBar::BaseInfiniteProgressBar(const wstring& progressBarName, const utility::ComponentSettings& settings, BaseComponent* parent, int animationPeriod) :
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
		),
		animationPeriod(animationPeriod)
	{
		this->playAnimation();
	}

	void BaseInfiniteProgressBar::playAnimation()
	{
		SendMessageW(handle, PBM_SETMARQUEE, true, animationPeriod);
	}

	void BaseInfiniteProgressBar::stopAnimation()
	{
		SendMessageW(handle, PBM_SETMARQUEE, false, NULL);
	}

	void BaseInfiniteProgressBar::setAnimationPeriod(int animationPeriod)
	{
		this->animationPeriod = animationPeriod;
	}

	int BaseInfiniteProgressBar::getAnimationPeriod() const
	{
		return animationPeriod;
	}
}
