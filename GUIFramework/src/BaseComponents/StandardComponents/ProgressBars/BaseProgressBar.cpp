#include "BaseProgressBar.h"

#include "Styles/DefaultStyles.h"
#include "Exceptions/NotImplemented.h"

using namespace std;

namespace gui_framework
{
	BaseProgressBar::BaseProgressBar(const wstring& progressBarName, const utility::ComponentSettings& settings, BaseComposite* parent, int minRange, int maxRange, int updateStep) :
		BaseComponent
		(
			standard_classes::progressBar,
			progressBarName,
			settings,
			styles::DefaultStyles(),
			parent
		),
		IProgressBarColor
		(
			handle
		),
		minRange(minRange),
		maxRange(maxRange),
		updateStep(updateStep)
	{

	}

	void BaseProgressBar::update(int newPosition)
	{
		SendMessageW(handle, PBM_SETPOS, newPosition, NULL);
	}

	void BaseProgressBar::update()
	{
		SendMessageW(handle, PBM_STEPIT, NULL, NULL);
	}

	void BaseProgressBar::advancePosition(int position)
	{
		SendMessageW(handle, PBM_DELTAPOS, position, NULL);
	}

	void BaseProgressBar::setMinRange(int minRange)
	{
		SendMessageW(handle, PBM_SETRANGE32, minRange, maxRange);

		this->minRange = minRange;
	}

	void BaseProgressBar::setMaxRange(int maxRange)
	{
		SendMessageW(handle, PBM_SETRANGE32, minRange, maxRange);

		this->maxRange = maxRange;
	}

	void BaseProgressBar::setUpdateStep(int updateStep)
	{
		this->updateStep = updateStep;

		SendMessageW(handle, PBM_SETSTEP, updateStep, NULL);
	}

	int BaseProgressBar::getUpdateStep() const
	{
		return updateStep;
	}

	int BaseProgressBar::getMinRange() const
	{
		return minRange;
	}

	int BaseProgressBar::getMaxRange() const
	{
		return maxRange;
	}

	void BaseProgressBar::setBackgroundColor(uint8_t red, uint8_t green, uint8_t blue)
	{
		BaseComponent::setBackgroundColor(red, green, blue);

		IProgressBarColor::setProgressBarBackgroundColor(red, green, blue);
	}

	void BaseProgressBar::setProgressBarBackgroundColor(uint8_t red, uint8_t green, uint8_t blue)
	{
		BaseComponent::setBackgroundColor(red, green, blue);

		IProgressBarColor::setProgressBarBackgroundColor(red, green, blue);
	}

	void BaseProgressBar::setTextColor(uint8_t red, uint8_t green, uint8_t blue)
	{
		__utility::throwNotImplementedException(__FUNCTION__, "BaseProgressBar"sv);
	}

	json::JSONBuilder BaseProgressBar::getStructure() const
	{
		using json::utility::jsonObject;

		json::JSONBuilder builder = BaseComponent::getStructure();
		jsonObject& current = get<jsonObject>(builder[utility::to_string(windowName, ISerializable::getCodepage())]);

		current.data.push_back({ "minRange"s, static_cast<int64_t>(minRange) });
		current.data.push_back({ "maxRange"s, static_cast<int64_t>(maxRange) });

		current.data.push_back({ "updateStep"s, static_cast<int64_t>(updateStep) });

		return builder;
	}
}
