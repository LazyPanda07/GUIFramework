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
}
