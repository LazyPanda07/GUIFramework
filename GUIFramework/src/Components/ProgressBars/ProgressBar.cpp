#include "pch.h"
#include "ProgressBar.h"

using namespace std;

namespace gui_framework
{
	ProgressBar::ProgressBar(const wstring& progressBarName, const utility::ComponentSettings& settings, BaseComponent* parent, int minRange, int maxRange, int updateStep) :
		BaseProgressBar
		(
			progressBarName,
			settings,
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

	json::JSONBuilder ProgressBar::getStructure() const
	{
		using json::utility::jsonObject;
		using json::utility::objectSmartPointer;

		json::JSONBuilder builder = BaseProgressBar::getStructure();
		objectSmartPointer<jsonObject>& current = get<objectSmartPointer<jsonObject>>(builder[utility::to_string(windowName, ISerializable::getCodepage())]);

		__utility::changeClassName(current, serialized_classes::progressBar);

		return builder;
	}
}
