#include "pch.h"
#include "ProgressBarCreator.h"

#include "Components/ProgressBar.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		BaseComponent* ProgressBarCreator::create(const wstring& windowName, const utility::ComponentSettings& settings, const any& additionalData, BaseComponent* parent)
		{
			ProgressBar* result = new ProgressBar(windowName, settings.x, settings.y, settings.width, settings.height, parent);
			int updateStep = any_cast<int>(additionalData);

			if(updateStep)
			{
				result->setUpdateStep(updateStep);
			}

			return result;
		}
	}
}
