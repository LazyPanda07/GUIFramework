#include "core.h"
#include "InfiniteProgressBarCreator.h"

#include "Components/ProgressBars/InfiniteProgressBar.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		BaseComponent* InfiniteProgressBarCreator::create(const wstring& windowName, const utility::ComponentSettings& settings, const any& additionalData, BaseComponent* parent)
		{
			return new InfiniteProgressBar(windowName, settings, parent, any_cast<int>(additionalData));
		}
	}
}
