#include "pch.h"
#include "InfiniteProgressBar.h"

using namespace std;

namespace gui_framework
{
	InfiniteProgressBar::InfiniteProgressBar(const wstring& progressBarName, const utility::ComponentSettings& settings, BaseComponent* parent, int animationPeriod) :
		BaseInfiniteProgressBar
		(
			progressBarName,
			settings,
			parent,
			animationPeriod
		),
		IResizableComponent
		(
			handle,
			parent->getHandle()
		)
	{
		
	}

	json::JSONBuilder InfiniteProgressBar::getStructure() const
	{
		using json::utility::jsonObject;
		using json::utility::objectSmartPointer;

		json::JSONBuilder builder = BaseInfiniteProgressBar::getStructure();
		objectSmartPointer<jsonObject>& current = get<objectSmartPointer<jsonObject>>(builder[utility::to_string(windowName, ISerializable::getCodepage())]);

		__utility::changeClassName(current, serialized_classes::infiniteProgressBar);

		return builder;
	}
}
