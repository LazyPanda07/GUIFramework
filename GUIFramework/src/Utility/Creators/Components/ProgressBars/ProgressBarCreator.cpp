#include "ProgressBarCreator.h"

#include "Components/ProgressBars/ProgressBar.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		BaseComponent* ProgressBarCreator::create(const wstring& windowName, const utility::ComponentSettings& settings, const any& additionalData, BaseComposite* parent)
		{
			auto [minRange, maxRange, updateStep] = any_cast<tuple<int, int, int>>(additionalData);

			return new ProgressBar(windowName, settings, parent, minRange, maxRange, updateStep);
		}
	}
}
