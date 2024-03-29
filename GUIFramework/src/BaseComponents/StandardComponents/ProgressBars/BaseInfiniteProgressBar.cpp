#include "BaseInfiniteProgressBar.h"

#include "Styles/Components/InfiniteProgressBarStyles.h"
#include "Exceptions/NotImplemented.h"

using namespace std;

namespace gui_framework
{
	BaseInfiniteProgressBar::BaseInfiniteProgressBar(const wstring& progressBarName, const utility::ComponentSettings& settings, BaseComposite* parent, int animationPeriod) :
		BaseComponent
		(
			standard_classes::progressBar,
			progressBarName,
			settings,
			styles::InfiniteProgressBarStyles(),
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
		BaseComponent::setBackgroundColor(red, green, blue);

		IProgressBarColor::setProgressBarBackgroundColor(red, green, blue);
	}

	void BaseInfiniteProgressBar::setProgressBarBackgroundColor(uint8_t red, uint8_t green, uint8_t blue)
	{
		BaseComponent::setBackgroundColor(red, green, blue);

		IProgressBarColor::setProgressBarBackgroundColor(red, green, blue);
	}

	void BaseInfiniteProgressBar::setTextColor(uint8_t red, uint8_t green, uint8_t blue)
	{
		__utility::throwNotImplementedException(__FUNCTION__, "BaseInfiniteProgressBar"sv);
	}

	json::JSONBuilder BaseInfiniteProgressBar::getStructure() const
	{
		using json::utility::jsonObject;

		json::JSONBuilder builder = BaseComponent::getStructure();
		get<jsonObject>(builder[utility::to_string(windowName, ISerializable::getCodepage())]).data.push_back({ "animationPeriod"s, static_cast<int64_t>(animationPeriod) });

		return builder;
	}
}
