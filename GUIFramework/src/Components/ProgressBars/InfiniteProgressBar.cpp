#include "InfiniteProgressBar.h"

#include "BaseComposites/BaseComposite.h"

using namespace std;

namespace gui_framework
{
	InfiniteProgressBar::InfiniteProgressBar(const wstring& progressBarName, const utility::ComponentSettings& settings, BaseComposite* parent, int animationPeriod) :
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

	size_t InfiniteProgressBar::getHash() const
	{
		return typeid(InfiniteProgressBar).hash_code();
	}

	json::JSONBuilder InfiniteProgressBar::getStructure() const
	{
		using json::utility::jsonObject;

		json::JSONBuilder builder = BaseInfiniteProgressBar::getStructure();
		jsonObject& current = get<jsonObject>(builder[utility::to_string(windowName, ISerializable::getCodepage())]);

		return builder;
	}
}
