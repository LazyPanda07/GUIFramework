#include "pch.h"
#include "InfiniteProgressBarCreator.h"

#include "Components/InfiniteProgressBar.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		BaseComponent* InfiniteProgressBarCreator::create(const wstring& windowName, const utility::ComponentSettings& settings, const any& additionalData, BaseComponent* parent)
		{
			return new InfiniteProgressBar(windowName, utility::ComponentSettings(settings.x, settings.y, settings.width, settings.height), parent, any_cast<int>(additionalData));
		}
	}
}
