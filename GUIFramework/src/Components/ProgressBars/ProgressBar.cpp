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
}
