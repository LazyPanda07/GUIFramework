#include "pch.h"
#include "BaseInfiniteProgressBar.h"

#include "Exceptions/NotImplemented.h"

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
		IProgressBarColor
		(
			handle
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

	void BaseInfiniteProgressBar::setBackgroundColor(uint8_t red, uint8_t green, uint8_t blue)
	{
		IProgressBarColor::setProgressBarBackgroundColor(red, green, blue);
	}

	void BaseInfiniteProgressBar::setTextColor(uint8_t red, uint8_t green, uint8_t blue)
	{
		throw exceptions::NotImplemented(__FUNCTION__, "BaseInfiniteProgressBar");
	}
}
