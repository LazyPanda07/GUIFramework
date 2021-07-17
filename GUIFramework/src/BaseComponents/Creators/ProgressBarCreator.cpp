#include "pch.h"
#include "ProgressBarCreator.h"

#include "Components/ProgressBars/ProgressBar.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		BaseComponent* ProgressBarCreator::create(const wstring& windowName, const utility::ComponentSettings& settings, const any& additionalData, BaseComponent* parent)
		{
			auto [minRange, maxRange, updateStep] = any_cast<tuple<int, int, int>>(additionalData);

			return new ProgressBar(windowName, utility::ComponentSettings(settings.x, settings.y, settings.width, settings.height), parent, minRange, maxRange, updateStep);
		}
	}
}
